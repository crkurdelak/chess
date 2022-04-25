/**
 * @file King.h
 * @brief Declarations for the King class.
 */

#ifndef KING_H
#define KING_H

#include <iostream>
#include "Piece.h"

/**
 * @brief A class representing a king.
 */
class King : public Piece {
  public:
    /**
     * @brief Creates a new king.
     * @param color the color of the king
     * @param location the location of the king
     */
    explicit King(Piece::Color color, Square& location) : Piece(color, location) { }


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


    /**
     *
     * @copydoc Piece::needs_clear_path
     */
    bool needs_clear_path() const override;
};

#endif
