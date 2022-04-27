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
        Square* old_location = this->location();
        old_location->set_occupant(nullptr);
    }
    if (location != nullptr) {
        location->set_occupant(this);
    }
    _location = location;
}

bool Piece::is_on_square() const {
    return _location != nullptr;
}

bool Piece::move_to(Square &location) {
    bool is_successful = false;
    if ( this->is_on_square() && this->can_move_to(location)) {
        if (location.is_occupied()) {
            location.occupant()->capture();
        }
        this->set_location(&location);
        is_successful = true;
    }

    return is_successful;
}

void Piece::capture() {
    this->location()->set_occupant(nullptr);
    this->set_location(nullptr);
}
