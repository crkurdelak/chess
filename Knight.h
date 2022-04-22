/**
 * @file Knight.h
 * @brief Declarations for the Knight class.
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "Piece.h"


/**
 * @brief A class representing a knight.
 */
class Knight : public Piece {
  public:
    /**
     * @brief Creates a new knight.
     * @param color the color of the knight
     * @param location the location of the knight
     */
    Knight(Piece::Color color, Square& location) : Piece(color, location) { }


    /**
     *
     * @copydoc Piece::value
     */
    piece_value_t value() const override;


    /**
     *
     * @copydoc Piece::can_move_to
     */
    bool can_move_to(const Square& location) const override;


    /**
     *
     * @copydoc Piece::str
     */
    std::string str() const override;
};

#endif
