cmake_minimum_required(VERSION 3.16)
project(wallChess__)

set(CMAKE_CXX_STANDARD 14)

add_executable(wallChess__ main.cpp ChessPiece.cpp ChessPiece.h ChessBoard.cpp ChessBoard.h Square.cpp Square.h King.cpp King.h Rook.cpp Rook.h Square.cpp Square.h)