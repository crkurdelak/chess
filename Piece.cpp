/**
 * @file Piece.cpp
 * @brief Implementation of the Piece class.
 */

#include "Piece.h"
#include "Square.h"

Piece::Color Piece::color() const {
    return _color;
}

Square *Piece::location() const {
    return _location;
}

void Piece::set_location(Square *location) {
    if (this->location() != nullptr) {
        Square old_location = *this->location();
        old_location.set_occupant(nullptr);
    }
    location->set_occupant(this);
    _location = location;
}

bool Piece::is_on_square() const {
    return _location != nullptr;
}

bool Piece::move_to(Square &location) {
    bool result = false;
    if (can_move_to(location)) {
        set_location(&location);
        result = true;
    }

    return result;
}

void Piece::capture() {
    // TODO implement capture
}
