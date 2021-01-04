//
// Created by ace09 on 1/3/2021.
//

#ifndef WALLCHESS___CHESSPIECE_H
#define WALLCHESS___CHESSPIECE_H

#include "ChessBoard.h"
#include "Square.h"
#include <memory>

enum  CHESSCOLOR  {WHITE, BLACK};
enum CHESSPIECE_STATUS {LIVE, CAPTURED};

namespace Chess {
    class ChessPiece {
    private:
        CHESSCOLOR color;
        std::shared_ptr<ChessBoard> board;
        std::shared_ptr<Square> location;
    protected:
        ChessPiece(CHESSCOLOR color, std::shared_ptr<ChessBoard> board) {
            this->color = color;
            this->board = std::move(board);

        }
        // TODO: Restrict copy/assign

//    std::unique_ptr<Square> location;
//    std::shared_ptr<MoveStrategy> moveStrategy;


    public:
        std::unique_ptr<ChessPiece> New() = 0;

        virtual ~ChessPiece() = default;

        virtual bool isCaptured() = 0;
        virtual bool GetHasMoved() = 0;

        CHESSCOLOR getColor() { return this->color; };

        virtual std::string toString() = 0;

        virtual std::string shorthand() = 0;

        virtual bool CheckMove(std::shared_ptr<Square> dest) = 0;

        virtual bool MakeMove(std::shared_ptr<Square> dest) = 0;

        void SetMoved() { this->HasMoved = true; };
        std::shared_ptr<Square> GetLocation(){ return this.location }
        virtual std::set<std::shared_ptr<Square>> GetPossibleMoves() = 0;
    };
} // namespace Chess

#endif //WALLCHESS___CHESSPIECE_H
