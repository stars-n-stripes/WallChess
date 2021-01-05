//
// Created by ace09 on 1/3/2021.
//
#pragma once
#ifndef WALLCHESS___CHESSBOARD_H
#define WALLCHESS___CHESSBOARD_H

#include "Square.h"
#include "ChessPiece.h"
#include <vector>
#include <memory>

namespace Chess {
    // TODO: Fix the ungodly amount of forward definition in this project.
    class Square;
    class ChessPiece;
    class ChessBoard {
// Note for later: when interacting with the lichess API, we will need to have move output be in UCI
//  wbec-ridderkerk.nl/html/UCIProtocol.html
    public:
        static CHESSCOLOR CheckCheck(ChessPiece* moving_piece, std::shared_ptr<Square> tgt_square);

        // Iterator that provides a list of square-ptrs between two given squares, either on a diagonal, row, or column.
        static std::vector<std::shared_ptr<Square>>
        SquareRange(const std::shared_ptr<Square> &a, std::shared_ptr<Square> b);

        // Get a particular square
        static std::shared_ptr<Square> GetSquare(int x, int y);

        /// Shorthand for checking the current board state
        /// \return
        static CHESSCOLOR CheckCheck();
    };
}
#endif //WALLCHESS___CHESSBOARD_H
 //namespace Chess