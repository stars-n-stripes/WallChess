//
// Created by ace09 on 1/3/2021.
//
#pragma once
#ifndef WALLCHESS___CHESSBOARD_H
#define WALLCHESS___CHESSBOARD_H


#include "ChessPiece.h"
#include <vector>
#include <memory>
#include "Square.h"

namespace Chess {
    class ChessBoard {
// Note for later: when interacting with the lichess API, we will need to have move output be in UCI
//  wbec-ridderkerk.nl/html/UCIProtocol.html
    public:
        CHESSCOLOR CheckCheck();

        // Iterator that provides a list of square-ptrs between two given squares, either on a diagonal, row, or column.
        static std::vector<std::shared_ptr<Square>> SquareRange(std::shared_ptr<Square> a, std::shared_ptr<Square> b);
        // Get a particular square
        static std::shared_ptr<Square> GetSquare(int x, int y);
    };
}

#endif //WALLCHESS___CHESSBOARD_H
