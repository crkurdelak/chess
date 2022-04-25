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
    bool result = false;
    if (this -> location() != nullptr) {
        if (&location != this->location()) {
            // black can only move to smaller rank numbers (larger indices)
            if (this->color() == Piece::Color::black) {
                if (location.occupant() == nullptr) {
                    // pawns that have not been moved can move forward two squares
                    if (!_moved) {
                        if (location.rank() == this->location()->rank() + 2
                            && location.file() == this->location()->file()) {
                            result = true;
                        }
                    }
                    else {
                        if (location.rank() == this->location()->rank() + 1
                            && location.file() == this->location()->file()) {
                            result = true;
                        }
                    }
                }
                // if it's trying to capture, make sure it's one diagonal square
                else if (location.occupant()->color() != this->color()) {
                    if ((location.rank() == this->location()->rank() + 1)
                        && (location.file() == this->location()->file() + 1
                        || location.file() == this->location()->file() - 1)) {
                        result = true;
                    }
                }
            }
            // white can only move to larger rank number (smaller indices)
            else {
                if (location.occupant() == nullptr) {
                    // pawns that have not been moved can move forward two squares
                    if (!_moved) {
                        if (location.rank() == this->location()->rank() - 2
                            && location.file() == this->location()->file()) {
                            result = true;
                        }
                    }
                    else {
                        if (location.rank() == this->location()->rank() - 1
                            && location.file() == this->location()->file()) {
                            result = true;
                        }
                    }
                }
                else if (location.occupant()->color() != this->color()) {
                    // if it's trying to capture, make sure it's one diagonal square
                    if ((location.rank() == this->location()->rank() - 1)
                        && (location.file() == this->location()->file() + 1
                        || location.file() == this->location()->file() - 1)) {
                        result = true;
                    }
                }
            }
        }
    }
    return result;
}


bool Pawn::move_to(Square &location) {
    // TODO find out if this or can_move_to should be handling unmoved pawns moving two squares
    // needs to be able to move 2 spaces if this pawn has not moved yet
    bool result = Piece::move_to(location);
    if (result) {
        _moved = true;
    }
    return result;
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


bool Pawn::needs_clear_path() const {
    return true;
}


