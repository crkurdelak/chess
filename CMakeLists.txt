cmake_minimum_required(VERSION 3.21)
project(chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(chess
        Bishop.cpp

        Board.cpp

        King.cpp

        Knight.cpp

        Pawn.cpp

        Piece.cpp

        Queen.cpp

        Rook.cpp
        Square.cpp ChessDemo.cpp)
