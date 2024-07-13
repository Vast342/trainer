#include "dataload.h"

BFEntry DataLoader::getPosition() {
    return batch[++currentEntry];
}

void DataLoader::loadBatch() {
    std::vector<char> batchChar(sizeof(batch) / sizeof(char));
    stream.read(batchChar.data(), 32 * batchSize);
    if(stream.eof()) {
        stream.close();
        stream.open(data, std::ios::binary);
        stream.read(batchChar.data(), 32 * batchSize);
    }
    std::memcpy(batch.data(), batchChar.data(), 32 * batchSize);
    currentEntry = 0;
}