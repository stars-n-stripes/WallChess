//
// Created by ace09 on 1/5/2021.
//

#ifndef WALLCHESS___VISUALIZER_H
#define WALLCHESS___VISUALIZER_H

#include "ChessBoard.h"
#include <string>

/// Abstract visualizer class that declares the functions that the GameBoard will expect to be able to call when
/// displaying the board.
/// Any visualizer (console, wall, etc) needs to implement these functions.
namespace Chess {
    class Visualizer {
        std::string BoardString;
    public:
        virtual void DrawBoard() = 0;
        virtual void HighlightSquare(int x, int y) = 0;
        virtual void UnHighlight(int x, int y) = 0;
        virtual void ClearHighlights() = 0;
        virtual void StartBlink() = 0;
        virtual void StopBlink() = 0;

    };
}


#endif //WALLCHESS___VISUALIZER_H
