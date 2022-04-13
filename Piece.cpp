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
    set_location(&location);
    return true;
}
