#pragma once
#include <iostream>
#include <cstdint>
#include <cassert>
#include <string_view>
#include <array>
#include <bit>
#include <ranges>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <chrono>
#include <fstream>
#include <thread>
#include <memory>
#include <cstring>
#include <filesystem>

// splits a string into segments based on the seperator
inline std::vector<std::string> split(const std::string string, const char seperator) {
    std::stringstream stream(string);
    std::string segment;
    std::vector<std::string> list;

    // every time that it can get a segment
    while(std::getline(stream, segment, seperator)) {
        // add it to the vector
        list.push_back(segment);
    }
    
    return list;
}

// takes a piece number and gets the type of it
constexpr int getType(int value) {
    return value & 7;
}
// takes a piece number and gets the color of it
constexpr int getColor(int value) {
    return value >> 3;
}