#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "Piece.h"

class Rook : public Piece {
  public:
    /**
     * @brief Creates a new rook with the given color and location.
     * @param color the color of the rook
     * @param location the location of the rook
     */
    Rook(Piece::Color color, Square& location) : Piece(color, location) { }


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
