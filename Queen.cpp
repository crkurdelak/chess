#include "Queen.h"
#include "Square.h"

piece_value_t Queen::value() const {
    return 9;
}

bool Queen::can_move_to(const Square &location) const {
    const double EPSILON = 1e-10;
    bool result = false;
    double slope = (location.rank() * 1.0 - this -> location()->rank()) / (location.file() * 1.0 -
            this -> location()->file());

    if (&location != this -> location()
    && (slope - 1 <= EPSILON
    || slope + 1 <= EPSILON
    || location.file() == this -> location()->file()
    ||location.rank() == this -> location()->rank())) {
        result = true;
    }
    return result;
}

std::string Queen::str() const {
    std::string piece_symbol;
    if (this -> color() == Piece::Color::black) {
        piece_symbol = "♛";
    }
    else {
        piece_symbol = "♕";
    }
    return piece_symbol;
}
