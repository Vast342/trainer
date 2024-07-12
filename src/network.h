#pragma once
#include "includes.h"
#include "arch.h"

constexpr float min = -1.98;
constexpr float max =  1.98;

inline float randInRange(float minimum = min, float maximum = max) {
    return minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum-minimum)));
}

struct Network {
    alignas(32) std::array<float, inputSize * inputBucketCount * layer1Size> featureWeights;
    alignas(32) std::array<float, layer1Size> featureBiases;
    alignas(32) std::array<float, layer1Size * 2 * outputBucketCount> outputWeights;
    alignas(32) std::array<float, outputBucketCount> outputBiases;
    Network() {
        init();
    }
    void init() {
        for(uint32_t i = 0; i < featureWeights.size(); i++) {
            featureWeights[i] = randInRange();
        }
        for(uint32_t i = 0; i < featureBiases.size(); i++) {
            featureBiases[i]  = randInRange();
        }
        for(uint32_t i = 0; i < outputWeights.size(); i++) {
            outputWeights[i]  = randInRange();
        }
        for(uint32_t i = 0; i < outputBiases.size(); i++) {
            outputBiases[i]   = randInRange();
        }
    }
};

struct QuantisedNetwork {
    alignas(32) std::array<int16_t, inputSize * inputBucketCount * layer1Size> featureWeights;
    alignas(32) std::array<int16_t, layer1Size> featureBiases;
    alignas(32) std::array<int16_t, layer1Size * 2 * outputBucketCount> outputWeights;
    alignas(32) std::array<int16_t, outputBucketCount> outputBiases;
    QuantisedNetwork(Network network) {
        for(uint32_t i = 0; i < featureWeights.size(); i++) {
            featureWeights[i] = static_cast<int16_t>(network.featureWeights[i] * qA);
        }
        for(uint32_t i = 0; i < featureBiases.size(); i++) {
            featureBiases[i]  = static_cast<int16_t>(network.featureBiases[i]  * qA);
        }
        for(uint32_t i = 0; i < outputWeights.size(); i++) {
            outputWeights[i]  = static_cast<int16_t>(network.outputWeights[i]  * qB);
        }
        for(uint32_t i = 0; i < outputBiases.size(); i++) {
            outputBiases[i]   = static_cast<int16_t>(network.outputBiases[i]   * qAB);
        }
    }
};
