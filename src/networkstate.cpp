#include "networkstate.h"

constexpr uint32_t ColorStride = 64 * 6;
constexpr uint32_t PieceStride = 64;

std::pair<uint32_t, uint32_t> NetworkState::getFeatureIndices(int square, int piece, int blackKing, int whiteKing) {
    return {getFeatureIndex(square, piece, 0, blackKing), getFeatureIndex(square, piece, 1, whiteKing)};
}

int NetworkState::getFeatureIndex(int square, int piece, int color, int king) {
    int c = getColor(piece) == color ? 0 : 1;
    if(color == 0) {
        square ^= 56;
        king ^= 56;
    }
    if constexpr (isMirrored) {
        if(king % 8 > 3) {
            square ^= 7;
            king ^= 7;
        }
    }
    return inputBuckets[king] * inputSize + c * ColorStride + getType(piece) * PieceStride + square;
}

int getBucket(int pieceCount) {
    const int divisor = (32 + outputBucketCount - 1) / outputBucketCount;
    return (pieceCount - 2) / divisor;
}

NetworkState::NetworkState(Network *net, BFEntry position) {
    network = net;
    initializeAccumulators(network->featureBiases);
    uint64_t occ = position.occupiedBitboard;
    int i = 0;
    int j = 0;
    while(occ != 0) {
        const int index = popLSB(occ);
        const int piece = 
        j++;
        if(j == 2) {

        }
    }
}

void NetworkState::initializeAccumulators(std::span<const float, layer1Size> bias) {
    std::copy(bias.begin(), bias.end(), black.begin());
    std::copy(bias.begin(), bias.end(), white.begin());
}


void NetworkState::activateFeature(int square, int piece, int blackKing, int whiteKing) { 
    const auto [blackIdx, whiteIdx] = getFeatureIndices(square, piece, blackKing, whiteKing);

    // change values for all of them
    for(int i = 0; i < layer1Size; ++i) {
        black[i] += network->featureWeights[blackIdx * layer1Size + i];
        white[i] += network->featureWeights[whiteIdx * layer1Size + i];
    }
}

float NetworkState::evaluate() {
    float sum = 0;

    for(int i = 0; i < layer1Size; ++i) {
        float activated = std::clamp(static_cast<int>(white[i]), 0, 1);
        activated *= activated;
        sum += activated * network->featureWeights[i];

        activated = std::clamp(static_cast<int>(black[i]), 0, 1);
        activated *= activated;
        sum += activated * network->featureWeights[layer1Size + i];
    }

    return sum;
}