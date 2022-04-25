/**
 * @file Pawn.cpp
 * @brief Implementation of the Pawn class.
 */

#include "Pawn.h"
#include "Square.h"

piece_value_t Pawn::value() const {
    return 1;
}

bool Pawn::can_move_to(const Square &location) const {
    // TODO make it able to move one diagonal square to capture
    bool result = false;
    if (this -> location() != nullptr) {
        if (&location != this->location()) {
            // black can only move to smaller rank numbers (larger indices)
            if (this->color() == Piece::Color::black) {
                if (location.rank() == this->location()->rank() + 1
                && location.file() == this->location()->file()) {
                    result = true;
                }
            }
            // white can only move to larger rank number (smaller indices)
            else {
                if (location.rank() == this->location()->rank() - 1
                && location.file() == this->location()->file()) {
                    result = true;
                }
            }
        }
    }
    return result;
}


bool Pawn::move_to(Square &location) {
    // TODO implement move_to
    // needs to be able to move 2 spaces if this pawn has not moved yet
    return Piece::move_to(location);
}


std::string Pawn::str() const {
    std::string piece_symbol;
    if (this -> color() == Piece::Color::black) {
        //piece_symbol = "♟";
        piece_symbol = "P";
    }
    else {
        //piece_symbol = "♙";
        piece_symbol = "p";
    }
    return piece_symbol;
}


bool needs_clear_path() {
    return true;
}


