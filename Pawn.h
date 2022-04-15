#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "Piece.h"

class Pawn : public Piece {
  public:
    /**
     * Creates a new pawn with the given color and location.
     * @param color the color of the pawn
     * @param location the location of the pawn
     */
    Pawn(Piece::Color color, Square& location) : Piece(color, location) { }


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

private:
    const unsigned int VALUE = 1;
};

#endif
