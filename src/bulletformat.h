#pragma once
#include "includes.h"
#include "network.h"


constexpr std::array<std::string_view, 64> squareNames = {
    "a1","b1","c1","d1","e1","f1","g1","h1",
    "a2","b2","c2","d2","e2","f2","g2","h2",
    "a3","b3","c3","d3","e3","f3","g3","h3",
    "a4","b4","c4","d4","e4","f4","g4","h4",
    "a5","b5","c5","d5","e5","f5","g5","h5",
    "a6","b6","c6","d6","e6","f6","g6","h6",
    "a7","b7","c7","d7","e7","f7","g7","h7",
    "a8","b8","c8","d8","e8","f8","g8","h8",
};
enum Pieces {
    Pawn, Knight, Bishop, Rook, Queen, King, None
};
constexpr int Black = 8;
constexpr int White = 0;

constexpr int colorToMove = 0;

struct TwoPieces {
    uint8_t value;
    uint8_t getSecond() {
        return value & 0b1111;
    }
    uint8_t getFirst() {
        return value >> 4;
    }
    uint8_t get(int j) {
        if(j == 0) return getFirst();
        if(j == 1) return getSecond();
        std::cerr << "out of range in TwoPieces.get()" << std::endl;
        return 10;
    }
};
struct BFEntry {
    uint64_t occupiedBitboard;
    std::array<TwoPieces, 16> pieces;
    int16_t score; // stm perspective score
    uint8_t result; // 0, 1, 2 = 0.0, 0.5, 1.0 from stm's perspective
    uint8_t ourKingSquare;
    uint8_t opponentKingSquare;
    std::array<uint8_t, 3> extras;
};