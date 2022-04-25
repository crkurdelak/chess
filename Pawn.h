/**
 * @file Pawn.h
 * @brief Declarations for the Pawn class.
 */

#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "Piece.h"

/**
 * @brief A class representing a pawn.
 */
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
     * @brief Moves this piece to the given location.
     *
     * Overrides move_to in Piece so that the pawn sets its "moved" flag and can move two squares
     * if it has not yet moved.
     *
     * @param location the new location
     * @return true if successful; else return false
     */
    bool move_to(Square& location) override;


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


private:
    bool _moved = false;

};

#endif
