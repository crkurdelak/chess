#include "Piece.h"
#include "Square.h"

Piece::Color Piece::color() const {
    return Piece::Color::black;
}

Square *Piece::location() const {
    return nullptr;
}

void Piece::set_location(Square *location) {

}

bool Piece::is_on_square() const {
    return false;
}

bool Piece::move_to(Square &location) {
    return false;
}
