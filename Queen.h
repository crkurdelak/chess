#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "Piece.h"

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
};

#endif
