//
// Created by ace09 on 1/3/2021.
//
#pragma once
#ifndef WALLCHESS___CHESSPIECE_H
#define WALLCHESS___CHESSPIECE_H

namespace Chess {
    enum class CHESSCOLOR  {WHITE, BLACK};
    enum class CHESSPIECE_STATUS {LIVE, CAPTURED};
}


#include "ChessBoard.h"
#include "Square.h"
#include <memory>
#include <set>



namespace Chess {
    class ChessBoard;
    class Square;
    class ChessPiece {
    private:
        CHESSCOLOR color;
        std::shared_ptr<ChessBoard> board;
        std::shared_ptr<Square> location;
        bool HasMoved;
    protected:
        ChessPiece(CHESSCOLOR color, std::shared_ptr<ChessBoard> board) {
            this->color = color;
            this->board = std::move(board);
            this->HasMoved = false;

        }
        // TODO: Restrict copy/assign

//    std::unique_ptr<Square> location;
//    std::shared_ptr<MoveStrategy> moveStrategy;


    public:
//        virtual std::unique_ptr<ChessPiece> New(CHESSCOLOR color, std::shared_ptr<ChessBoard> board, std::shared_ptr<Square> start) = 0;

        virtual ~ChessPiece() = default;

        virtual bool isCaptured() = 0;

        virtual bool GetHasMoved() = 0;

        CHESSCOLOR getColor() { return this->color; };

        virtual std::string toString() = 0;

        virtual std::string shorthand() = 0;

        virtual bool CheckMove(std::shared_ptr<Square> dest) = 0;

        virtual bool MakeMove(std::shared_ptr<Square> dest) = 0;

        void SetMoved() { this->HasMoved = true; };

        std::shared_ptr<Square> GetLocation() { return this->location; };

        virtual std::set<std::shared_ptr<Square>> GetPossibleMoves() = 0;
    };
}
#endif //WALLCHESS___CHESSPIECE_H
 // namespace Chess
