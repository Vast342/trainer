#pragma once

#include "includes.h"

/*
    Put your network arch and settings here
*/
inline std::string name = "cn_022";


constexpr int  inputSize         = 768;
constexpr int  inputBucketCount  = 2;
constexpr int  layer1Size        = 768;
constexpr int  outputBucketCount = 8;
constexpr bool isMirrored        = true;
constexpr std::array<int, 2>  quantisation = {255, 64};

constexpr std::array<int, 64> inputBuckets = {
    0, 0, 0, 0, 2, 2, 2, 2,
    0, 0, 0, 0, 2, 2, 2, 2,
    1, 1, 1, 1, 3, 3, 3, 3,
    1, 1, 1, 1, 3, 3, 3, 3,
    1, 1, 1, 1, 3, 3, 3, 3,
    1, 1, 1, 1, 3, 3, 3, 3,
    1, 1, 1, 1, 3, 3, 3, 3,
    1, 1, 1, 1, 3, 3, 3, 3
};

inline std::string data = "F:/bullet/bullet-main/data_shuffled.bin";
inline std::string outputFolder = "F:/ClearTrainer/";

constexpr int    evalScale    = 400;
constexpr int    batchSize    = 16384;
constexpr int    batchesPer   = 6104;
constexpr int    startSB      = 1;
constexpr int    endSB        = 500;
constexpr double wdlStart     = 0.3;
constexpr double wdlEnd       = 0.6;
constexpr double lrStart      = 0.001;
constexpr double lrMultiplier = 0.3;
constexpr int    lrStep       = 120;

constexpr int qA = quantisation[0];
constexpr int qB = quantisation[1];
constexpr int qAB = qA * qB;