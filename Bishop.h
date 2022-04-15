#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "Piece.h"

class Bishop : public Piece {
  public:
    /**
     * @brief Creates a new bishop with the given color and location.
     * @param color the color of the bishop
     * @param location the location of the bishop
     */
    Bishop(Piece::Color color, Square& location) : Piece(color, location) { }


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
    const unsigned int VALUE = 3;
};

#endif
