//
// Created by ace09 on 1/3/2021.
//

#ifndef WALLCHESS___MOVESTRATEGY_H
#define WALLCHESS___MOVESTRATEGY_H


class MoveStrategy {
public:
    std::function<bool(Square dest)> CheckMove;
    std::function<bool(Square dest)> MakeMove;

};


#endif //WALLCHESS___MOVESTRATEGY_H
