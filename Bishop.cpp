#include "Bishop.h"
#include "Square.h"

piece_value_t Bishop::value() const {
    return VALUE;
}

bool Bishop::can_move_to(const Square &location) const {
    const double EPSILON = 1e-10;
    bool result = false;
    if (this -> location() != nullptr) {
        double slope = (location.rank() * 1.0 - this->location()->rank()) / (location.file() * 1.0 -
                this->location()->file());

        if (&location != this->location()
            && (slope - 1 <= EPSILON
                || slope + 1 <= EPSILON)) {
            result = true;
        }
    }
    return result;
}

std::string Bishop::str() const {
    std::string piece_symbol;
    if (this -> color() == Piece::Color::black) {
        piece_symbol = "♝";
    }
    else {
        piece_symbol = "♗";
    }
    return piece_symbol;
}
