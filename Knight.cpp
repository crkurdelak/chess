#include "Knight.h"
#include "Square.h"

piece_value_t Knight::value() const {
    return 3;
}

bool Knight::can_move_to(const Square &location) const {
    const double EPSILON = 1e-10;
    bool result = false;
    if (this -> location() != nullptr) {
        double slope = (location.rank() * 1.0 - this->location()->rank()) / (location.file() * 1.0 -
                this->location()->file());
        // 2 squares in same file, one in rank +- 1 or 2 squares in same rank, one in file +- 1
        // (slope == 2 || slope == 1/2) && (rank +-1 || file +- 1)
        if (&location != this->location()
            && ((slope - 2 <= EPSILON
                 || slope - 0.5 <= EPSILON
                 || slope + 2 <= EPSILON
                 || slope + 0.5 <= EPSILON)
                && (location.rank() == this->location()->rank() + 1
                    || location.rank() == this->location()->rank() - 1
                    || location.file() == this->location()->file() + 1
                    || location.file() == this->location()->file() - 1))) {
            result = true;
        }
    }

    return result;
}

std::string Knight::str() const {
    std::string piece_symbol;
    if (this -> color() == Piece::Color::black) {
        piece_symbol = "♞";
    }
    else {
        piece_symbol = "♘";
    }
    return piece_symbol;
}
