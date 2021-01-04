//
// Created by ace09 on 1/3/2021.
//
#pragma once
#include <vector>
#include "ChessBoard.h"
#include "Square.h"

namespace Chess {
    std::vector<std::shared_ptr<Square>>
    Chess::ChessBoard::SquareRange(std::shared_ptr<Square> a, std::shared_ptr<Square> b) {
        return nullptr;
    }

    std::shared_ptr<Square> ChessBoard::GetSquare(int x, int y) {
        return std::shared_ptr<Square>();
    }
}