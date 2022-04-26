/**
 * @file Chess.cpp
 * @brief Implementation of the chess game.
 */

#include "Chess.h"
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"


/**
 * A main class for the chess game.
 * @return 0 on success, 1 if there is an error
 */
int main() {
    // TODO implement chess
    //Create a board.
    Board game_board = Board();

    //Create the black player and the white player, which should effectively lead to the creation
    // of all the black and white pieces and place them all on the board.
    Player black_player = Player(Piece::Color::black, game_board);
    Player white_player = Player(Piece::Color::white, game_board);

    // white has the first turn
    bool white_turn = true;

    // Points to the current player
    Player* current_player = &white_player;

    //Take turns by alternating between the white and black player.  For each turn, do the
    //following:
    for (int num_turns = 0; num_turns < 20; num_turns++) {
        //Print the board to standard output.
        std::cout << game_board;

        if(white_turn) {
            std::cout << "It's white's turn." << std::endl;
            current_player = &white_player;
        }
        else {
            std::cout << "It's black's turn." << std::endl;
            current_player = &black_player;
        }
        //Prompt the human user to enter a move (e.g., "a2 a4") on standard input.
        //Instruct the current player object to try to make the corresponding move.  If the move is
        //not valid, print an "invalid move" message, and prompt the user again; repeat until a
        //valid move is made.
        bool is_successful = false;

        std::cout << "Enter your move (e.g. a2 a4): " << std::endl;
        std::string move_str;
        std::getline(std::cin, move_str);
        std::string from = move_str.substr(0, 2);
        std::string to = move_str.substr(3, 2);

        is_successful = current_player->make_move(from, to);
        while (!is_successful) {
            std::cout << "Invalid move" << std::endl;
            std::cout << "Enter your move (e.g. a2 a4): " << std::endl;
            std::getline(std::cin, move_str);
            from = move_str.substr(0, 2);
            to = move_str.substr(3, 2);

            is_successful = current_player->make_move(from, to);
        }

        if (white_turn) {
            white_turn = false;
        }
        else {
            white_turn = true;
        }
    }

     //keep track of the total number of turns, and exit the game once a total of 20 turns have
     //been taken.
     //Once a game has ended, the board should be printed one last time, and total point value of
     //each player should be printed out.
     std::cout << "Game ended!" << std::endl;
     std::cout << game_board << std::endl;
     std::cout << "Black score: " << black_player.piece_value() << std::endl;
     std::cout << "White score: " << white_player.piece_value() << std::endl;
}
