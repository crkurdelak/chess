/**
 * @file Queen.h
 * @brief Declarations for the Queen class.
 */

#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "Piece.h"

/**
 * @brief A class representing a queen
 */
class Queen : public Piece {
  public:
    /**
     * @brief Creates a new queen.
     * @param color the color of the queen
     * @param location the location of the queen
     */
    Queen(Piece::Color color, Square& location) : Piece(color, location) { }


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
