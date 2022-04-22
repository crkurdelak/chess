/**
 * @file King.cpp
 * @brief DImplementation of the King class.
 */

#include "King.h"
#include "Square.h"

piece_value_t King::value() const {
    return 200;
}

bool King::can_move_to(const Square &location) const {
    const double EPSILON = 1e-10;
    bool result = false;
    if (this -> location() != nullptr) {
        double slope = (location.rank() * 1.0 - this->location()->rank()) / (location.file() * 1.0
                - this->location()->file());

        bool is_one_square = location.rank() == this->location()->rank() + 1
                || location.rank() == this->location()->rank() -1
                || location.file() == this->location()->file() + 1
                || location.file() == this->location()->file() - 1;

        if (((slope > 0
                && slope - 1 <= EPSILON)
            || (slope < 0
                && slope + 1 >= EPSILON)
            || location.file() == this->location()->file()
            ||location.rank() == this->location()->rank())
            && is_one_square) {
            result = true;
        }
    }
    return result;
}

std::string King::str() const {
    std::string piece_symbol;
    if (this -> color() == Piece::Color::black) {
        //piece_symbol = "♚";
        piece_symbol = "K";
    }
    else {
        //piece_symbol = "♔";
        piece_symbol = "k";
    }
    return piece_symbol;
}
