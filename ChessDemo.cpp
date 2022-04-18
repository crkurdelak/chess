//
// Created by crkur on 4/15/2022.
//
#include "Board.h"
#include "Pawn.h"


int main() {
    Board game_board = Board();
    Square& square = game_board.square_at(0, 0);
    new Pawn(Piece::Color::black, square);
    new Pawn(Piece::Color::white, game_board.square_at(7, 7));
    Piece &pawn = *square.occupant();
    Piece &white_pawn = *game_board.square_at(7, 7).occupant();
    std::cout << pawn.str() << std:: endl;
    std::cout << white_pawn.str() << std:: endl;
    std::cout << game_board << std::endl;

    bool can = pawn.can_move_to(game_board.square_at(1, 0));
    //1
    std::cout << can;
    //0
    std::cout << pawn.can_move_to(game_board.square_at(0, 1));
    //0
    std::cout << pawn.can_move_to(game_board.square_at(1, 5));
    //0
    std::cout << pawn.can_move_to(game_board.square_at(3, 1)) << std::endl;

    //1
    std::cout << white_pawn.can_move_to(game_board.square_at(6, 7));
    //0
    std::cout << white_pawn.can_move_to(game_board.square_at(7, 6));
    //0
    std::cout << white_pawn.can_move_to(game_board.square_at(4, 7));
    //0
    std::cout << white_pawn.can_move_to(game_board.square_at(3, 2));

    //game_board.~Board();
}

