//
// Created by crkur on 4/15/2022.
//
#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"


int main() {
    Board game_board = Board();
    Square& square = game_board.square_at(0, 0);
    new Pawn(Piece::Color::black, square);
    new Pawn(Piece::Color::white, game_board.square_at(7, 7));
    new Queen(Piece::Color::black, game_board.square_at(0, 3));
    new Queen(Piece::Color::white, game_board.square_at(7, 4));
    new King(Piece::Color::black, game_board.square_at(0, 4));
    new King(Piece::Color::white, game_board.square_at(7, 3));
    new Knight(Piece::Color::black, game_board.square_at(3, 5));
    new Knight(Piece::Color::white, game_board.square_at(7, 2));
    new Bishop(Piece::Color::black, game_board.square_at(0, 6));
    new Bishop(Piece::Color::white, game_board.square_at(7, 1));
    new Rook(Piece::Color::black, game_board.square_at(0, 7));
    new Rook(Piece::Color::white, game_board.square_at(7, 0));

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
    std::cout << white_pawn.can_move_to(game_board.square_at(3, 2)) << std::endl;

    //1 forward
    std::cout << game_board.square_at(0, 3).occupant()->can_move_to(game_board.square_at(3, 3));
    //1 sideways
    std::cout << game_board.square_at(0, 3).occupant()->can_move_to(game_board.square_at(0, 0));
    //1 diag
    std::cout << game_board.square_at(0, 3).occupant()->can_move_to(game_board.square_at(4, 7));
    //0 illegal
    std::cout << game_board.square_at(0, 3).occupant()->can_move_to(game_board.square_at(6, 0))
    << std::endl;

    //1 forward
    std::cout << game_board.square_at(0, 4).occupant()->can_move_to(game_board.square_at(1, 4));
    //1 sideways
    std::cout << game_board.square_at(0, 4).occupant()->can_move_to(game_board.square_at(0, 3));
    //1 diag
    std::cout << game_board.square_at(0, 4).occupant()->can_move_to(game_board.square_at(1, 5));
    //0 illegal
    std::cout << game_board.square_at(0, 4).occupant()->can_move_to(game_board.square_at(0, 6));
    //0 illegal
    std::cout << game_board.square_at(0, 4).occupant()->can_move_to(game_board.square_at(2, 4));
    //0 illegal
    std::cout << game_board.square_at(0, 4).occupant()->can_move_to(game_board.square_at(2, 6));
    //0 illegal
    std::cout << game_board.square_at(0, 4).occupant()->can_move_to(game_board.square_at(6, 0))
              << std::endl;

    //1 diag (slope -1)
    std::cout << game_board.square_at(0, 6).occupant()->can_move_to(game_board.square_at(1, 7));
    //1 diag (slope +1)
    std::cout << game_board.square_at(0, 6).occupant()->can_move_to(game_board.square_at(6, 0));
    //0 illegal
    std::cout << game_board.square_at(0, 6).occupant()->can_move_to(game_board.square_at(1, 2))
    << std::endl;

    //1 (slope )
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(5, 6));
    //1 (slope)
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(5, 4));
    //1 (slope )
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(4, 7));
    //1 (slope)
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(2, 7));
    //1 (slope )
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(4, 3));
    //1 (slope)
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(2, 3));
    //1 (slope )
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(1, 6));
    //1 (slope)
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(1, 4));
    //0
    std::cout << game_board.square_at(3, 5).occupant()->can_move_to(game_board.square_at(0, 2))
    << std::endl;


    //game_board.~Board();
}

