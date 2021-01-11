//
// Created by ace09 on 1/4/2021.
//

#include "Rook.h"
#include <string>

bool Chess::Rook::isCaptured() {
    return false;
}

bool Chess::Rook::GetHasMoved() {
    return false;
}

std::string Chess::Rook::toString() {
    return std::string();
}

std::string Chess::Rook::shorthand() {
    return std::string();
}

bool Chess::Rook::CheckMove(std::shared_ptr<Square> dest) {
    return false;
}

bool Chess::Rook::MakeMove(std::shared_ptr<Square> dest) {
    return false;
}
