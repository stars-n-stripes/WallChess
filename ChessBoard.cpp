//
// Created by ace09 on 1/3/2021.
//
#pragma once
#include <vector>
#include "ChessBoard.h"

namespace Chess {
    std::vector<std::shared_ptr<Square>>
    Chess::ChessBoard::SquareRange(const std::shared_ptr<Square> &a, std::shared_ptr<Square> b) {
        // TODO: Implement
        return std::vector<std::shared_ptr<Square>>();
    }

    std::shared_ptr<Square> ChessBoard::GetSquare(int x, int y) {
        return std::shared_ptr<Square>();
    }

    CHESSCOLOR ChessBoard::CheckCheck(ChessPiece *moving_piece, std::shared_ptr<Square> tgt_square) {
        return CHESSCOLOR::BLACK;
    }

    CHESSCOLOR ChessBoard::CheckCheck() {
        return CHESSCOLOR::BLACK;
    }


}