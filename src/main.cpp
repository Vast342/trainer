#include "includes.h"
#include "network.h"
#include "arch.h"
#include "train.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv) {
    // exposition
    std::cout << "Now beginning training of " << name << std::endl;
    std::cout << "Arch: (768" << (inputBucketCount == 1 ? "" : "x" + std::to_string(inputBucketCount)) << "->" << layer1Size << ")x2->1" << (outputBucketCount == 1 ? "" : "x" + std::to_string(outputBucketCount)) << std::endl;
    std::cout << "Data: " << data << std::endl;
    std::cout << "Number Of Positions: " << (std::filesystem::file_size(data) / 32) << std::endl;

    // actually call training
    Network network;
    train(network);

    // quantise and save
    QuantisedNetwork qNetwork(network);
    std::string outputDirectory = "cn_022-500.nnue";
    std::cout << "writing finished network to " << outputDirectory << std::endl;
    /* i'll figure this out after I figure out training lol
    std::ofstream out_file(outputDirectory, std::ios::binary);
    if (!out_file) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }
    out_file.write(reinterpret_cast<const char*>(&qNetwork), sizeof(qNetwork));
    out_file.close();*/
    return 0;
}