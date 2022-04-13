#include "Piece.h"
#include "Square.h"

Piece::Color Piece::color() const {
    return _color;
}

Square *Piece::location() const {
    return _location;
}

void Piece::set_location(Square *location) {
    _location = location;
}

bool Piece::is_on_square() const {
    return _location != nullptr;
}

bool Piece::move_to(Square &location) {
    Square old_location = * this->location();
    set_location(&location);
    location.set_occupant(this);
    old_location.set_occupant(nullptr);
    return true;
}
