#pragma once

#include "includes.h"
#include "network.h"
#include "bulletformat.h"

struct NetworkState {
    // accumulators
    alignas(32) std::array<float, layer1Size> black;
    alignas(32) std::array<float, layer1Size> white;
    Network *network;
    NetworkState(Network *net, BFEntry position);
    void reset();
    void initializeAccumulators(std::span<const float, layer1Size> bias);
    void activateFeature(int square, int type, int blackKing, int whiteKing);
    static std::pair<uint32_t, uint32_t> getFeatureIndices(int square, int type, int blackKing, int whiteKing);
    static int getFeatureIndex(int square, int type, int color, int king);
    float evaluate();
};