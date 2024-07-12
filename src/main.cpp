#include "network.h"
#include "arch.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv) {
    std::cout << "Now beginning training of " << name << std::endl;
    std::cout << "Arch: (768" << (inputBucketCount == 1 ? "" : "x" + std::to_string(inputBucketCount)) << "->" << layer1Size << ")x2->1" << (outputBucketCount == 1 ? "" : "x" + std::to_string(outputBucketCount)) << std::endl;
    std::cout << "Data: " << data << std::endl;
    //std::cout << "Number Of Positions: " << (std::filesystem::file_size(data) / 32);
    return 0;
}