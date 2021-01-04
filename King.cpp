//
// Created by ace09 on 1/3/2021.
//
#pragma once
#include "King.h"
#include "Rook.h"
#include <memory>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include "Square.h"

namespace Chess {
    King::King(CHESSCOLOR color, std::shared_ptr<ChessBoard> board) : ChessPiece(color, std::move(board)) {};

    std::unique_ptr<King>
    King::New(CHESSCOLOR newcolor, std::shared_ptr<ChessBoard>& gameboard, std::shared_ptr<Square>& start) {
        auto instance = new King(newcolor, std::move(gameboard));
        instance->OnCreate(std::move(start));

        return std::move(std::unique_ptr<King>(instance));
    }

    void King::OnCreate(std::shared_ptr<Square> start) {
        this->location = std::move(start);
    }

/// Check to see if a move is valid on the piece's board
/// \param dest: The Square that we want to move to
/// \return bool
    bool King::CheckMove(std::shared_ptr<Square> dest) {
        // Check if the move would place the owning player in check
        // out-of-bounds is "handled" by an out-of-bounds square not existing
        if (this->board->CheckCheck(this, dest) != this->color) { return false; };

//        // Acquire the distances between the King and the target square.
//        int h_dist, v_dist;
//        h_dist = abs(this->location->GetColumn() - dest->GetColumn());
//        v_dist = abs(this->location->GetRow() - dest->GetRow());
        // Check if the move is a possibility for this piece
        auto possibilities = this->GetPossibleMoves();
        // For the king, it includes both a normal move and whether or not a castle is possible anymore
        // https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
        // set.find() returns the end() iterator if there's nothing in the set
        if(possibilities.find(dest) == possibilities.end()){
            /* v contains x */
            return false;
        }

        // check if a friendly piece occupies that spot
        std::shared_ptr<ChessPiece> tgt = dest->GetPiece();
        if (tgt != nullptr){
            if (tgt->getColor() == this->color){
                return false;
            }
        }


        // Castles are the move Kings have solely to annoy programmers
        // Rules of Castling:
        // 1. Can't do it while in check
        // 2. Can't go through check
        // 3. Neither King nor Rook may have moved
        // 4. Can't go through any other pieces
        // Generate an iterator between the king and the rook
        // 2 == "C", 6 == "G"

        // Only need to check castle validity if the distance is 2
        if(dest->DistanceBetween(this->location) == 2){
            // C-column
            if(dest->GetColumn() == 2){
                auto edge = this->board->GetSquare(0, this->location->GetRow());
                auto cells_between = this->board->SquareRange(this->location, edge);
            }
            // H-column
            else if (dest->GetColumn() == 6){
                auto edge = this->board->GetSquare(7, this->location->GetRow());
                auto cells_between = this->board->SquareRange(this->location, edge);
            }
            }        // Move is valid
        return true;
        }





    /// Get a list of possible squares this piece may go to, without regard to if the move is valid or not
    /// \return
    std::set<std::shared_ptr<Square>> King::GetPossibleMoves() {

        std::set<std::shared_ptr<Square>> possible_moves;

        // Return all adjacent squares for the King
        for(int i = 0; i < 2; i ++ ){
            for(int j = 0; j < 2; j ++ ){
                auto square = this->board->GetSquare(i, j);
                possible_moves.emplace(std::move(square));
            }
        }
        // Additionally, if the king has not moved and a corresponding rook has not moved, add the corresponding castle move
        if(!this->HasMoved){
            // Use dynamic casts to cast ChessPiece to Rook
            // dc will return nullptr if that's not possible, namely, if the piece on that square is not a rook
            std::shared_ptr<Rook> a_rook = dynamic_cast<std::shared_ptr<Rook>>(this->board->GetSquare(0, this->location->GetRow())->GetPiece());
            std::shared_ptr<Rook> h_rook =  dynamic_cast<std::shared_ptr<Rook>>(this->board->GetSquare(7, this->location->GetRow()));
            // Verify that the pieces there are, in fact, Rooks, then see if they have moved.
            if (a_rook != nullptr){
                if(!a_rook->GetHasMoved()){
                   possible_moves.emplace(std::move(a_rook->GetLocation()));
                }
            }
            if (h_rook != nullptr){
                if(!h_rook->GetHasMoved()){
                    possible_moves.emplace(std::move(h_rook->GetLocation()));
                }
            }
        }
        return possible_moves;
    }

    bool King::MakeMove(std::shared_ptr<Square> dest) {
        return false;
    }

    bool King::GetHasMoved() {
        return this->HasMoved;
    }
}