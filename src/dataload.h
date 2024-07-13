#pragma once

#include "includes.h"
#include "bulletformat.h"

struct DataLoader {
    public: 
        DataLoader(std::string directory) {
            stream.open(directory, std::ios::binary);
            currentEntry = batchSize;
        }
        ~DataLoader() {
            stream.close();
        }
        BFEntry getPosition();
        void loadBatch();
    private:
        std::ifstream stream;
        std::array<BFEntry, batchSize> batch;
        int currentEntry;
};