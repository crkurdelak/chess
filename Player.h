/**
 * @file Player.h
 * @brief Declarations for the Player class.
 */

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H


#include <vector>
#include "Board.h"
#include "Piece.h"
#include "King.h"

/**
 * @brief A class representing a player in a chess game.
 */
class Player {
public:
    /**
     * @brief Creates a new player object.
     * @param color the color of this player
     * @param board the board where this player's pieces will go
     */
    Player(Piece::Color color, const Board& board);


    /**
     * @brief Returns the color of this player.
     * @return the color of this player
     */
    Piece::Color color() const;


    /**
     * @brief Moves the piece at the given "from" square to the given "to" square and returns
     * true if successful.
     * @param from the square to move a piece from
     * @param to the square to move a piece to
     * @return true if the move is successful; else returns false
     */
    bool make_move(const std::string& from, const std::string& to);


    /**
     * @brief Returns the combined value of all this player's pieces that are still on the board.
     * @return the combined value of all this player's pieces that are still on the board
     */
    piece_value_t piece_value() const;


    /**
     * @brief A destructor for the Player class.
     */
    ~Player();

private:
    const Piece::Color _color;
    const Board& _board;
    std::vector<Piece*> _pieces;
    King* _king;
};


#endif //CHESS_PLAYER_H
