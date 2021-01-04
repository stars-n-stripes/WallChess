//
// Created by ace09 on 1/4/2021.
//

#ifndef WALLCHESS___ROOK_H
#define WALLCHESS___ROOK_H

#include "ChessPiece.h"

namespace Chess {
    class Rook : public ChessPiece{
    public:
        bool isCaptured() override;

        bool GetHasMoved() override;

        std::string toString() override;

        std::string shorthand() override;

        bool CheckMove(std::unique_ptr<Square> &dest) override;

        bool MakeMove(std::unique_ptr<Square> &dest) override;
    };
}

#endif //WALLCHESS___ROOK_H
