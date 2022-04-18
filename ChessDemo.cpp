//
// Created by crkur on 4/15/2022.
//
#include "Board.h"
#include "Pawn.h"


int main() {
    Board game_board = Board();
    Square& square = game_board.square_at(0, 0);
    new Pawn(Piece::Color::black, square);
    Piece &pawn = *square.occupant();
    std::cout << pawn.str() << std:: endl;
    // TODO find out why it is not outputting the pawn on the board
    std::cout << game_board << std::endl;

    bool can = pawn.can_move_to(game_board.square_at(1, 0));
    std::cout << can;

    game_board.~Board();
}

