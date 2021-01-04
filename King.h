//
// Created by ace09 on 1/3/2021.
//
#pragma once
#ifndef WALLCHESS___KING_H
#define WALLCHESS___KING_H


#include <vector>
#include <set>
#include "ChessPiece.h"
#include "Square.h"
namespace Chess {
    class King : public ChessPiece {

        CHESSCOLOR color;
        CHESSPIECE_STATUS status;
        std::shared_ptr<ChessBoard> board;
        std::shared_ptr<Square> location;

        // Used for Kings and Rooks
        bool HasMoved{};
    protected:
        King(CHESSCOLOR color, std::shared_ptr<ChessBoard> board);

    public:
        ~King() = default;

        bool MakeMove(std::unique_ptr<Square> dest) override;

        bool isCaptured();

        CHESSCOLOR getColor() { return this->color; };

        std::string toString();

        std::string shorthand();

        bool MakeMove(std::unique_ptr<Square> &dest) override;

        bool CheckMove(std::shared_ptr<Square> dest) override;
        bool MakeMove(std::shared_ptr<Square> dest) override;
        bool GetHasMoved() override;
        std::set<std::shared_ptr<Square>> GetPossibleMoves() override;

        void OnCreate(std::shared_ptr<Square> start);

        std::unique_ptr<King>
        New(CHESSCOLOR newcolor, std::shared_ptr<ChessBoard> &gameboard, std::shared_ptr<Square> &start);
    };
} // namespace Chess
#endif //WALLCHESS___KING_H
