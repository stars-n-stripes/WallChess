//
// Created by ace09 on 1/3/2021.
//
#pragma once
#ifndef WALLCHESS___SQUARE_H
#define WALLCHESS___SQUARE_H


#include "ChessPiece.h"
#include <utility>

//#ifndef "CHESSPIECE_H"
//#define "CHESSPIECE_H"
#include <memory>

namespace Chess {
    class ChessPiece;
    class Square {
    private:
        int column;
        int row;
    public:
        int GetColumn();

        int GetRow();

        std::pair<int, int> GetCoords();

        std::shared_ptr<ChessPiece> GetPiece();

        int DistanceBetween(std::shared_ptr<Square> s);

    };

#endif //WALLCHESS___SQUARE_H
}
