#include "train.h"
#include "network.h"
#include "networkstate.h"
#include "dataload.h"
#include "arch.h"

void train([[maybe_unused]]Network &network) {
    // data loader teehee
    DataLoader loader = DataLoader(data);
    //auto start = std::chrono::steady_clock::now();
    //const auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
    for(int superBatch = startSB; superBatch <= endSB; superBatch++) {
        for(int batch = 0; batch < batchesPer; batch++) {
            // load batch into memory DONE
            loader.loadBatch();
            // define total gradient
            for(int pos = 0; pos < batchSize; pos++) {
                // get first position DONE
                BFEntry entry = loader.getPosition();
                // stuff it into network
                NetworkState state = NetworkState(&network, entry);
                // inference
                const float eval = sigmoid(state.evaluate(), 1);
                const float currentWDL = std::lerp(wdlStart, wdlEnd, double(superBatch) / double(endSB));
                const float expected = std::lerp(sigmoid(entry.score, evalScale), entry.result, currentWDL);
                const float error = std::pow(eval - expected, 2); 
                // backpropogate with error to get gradients
                // add gradient to a sum
            }
            // apply gradient / batchSize (maybe * lr??)
        }
    }
}
