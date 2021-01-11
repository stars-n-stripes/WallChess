//
// Created by ace09 on 1/7/2021.
//

#ifndef WALLCHESS___CONSOLEVISUALIZER_H
#define WALLCHESS___CONSOLEVISUALIZER_H

#include "Visualizer.h"

namespace Chess {
    class ConsoleVisualizer : public Visualizer {
    public:
        void DrawBoard() override;

        void HighlightSquare(int x, int y) override;

        void UnHighlight(int x, int y) override;

        void ClearHighlights() override;

        void StartBlink() override;

        void StopBlink() override;
    };
}

#endif //WALLCHESS___CONSOLEVISUALIZER_H
