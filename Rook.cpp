/**
 * @file Rook.cpp
 * @brief Implementation of the Rook class.
 */

#include "Rook.h"
#include "Square.h"

piece_value_t Rook::value() const {
    return 5;
}

bool Rook::can_move_to(const Square &location) const {
    bool  result = false;
    if (this -> location() != nullptr) {
        if (&location != this->location()
            && (location.file() == this->location()->file()
                || location.rank() == this->location()->rank())) {
            result = true;
        }
    }
    return result;
}

std::string Rook::str() const {
    std::string piece_symbol;
    if (this -> color() == Piece::Color::black) {
        //piece_symbol = "♜";
        piece_symbol = "R";
    }
    else {
        //piece_symbol = "♖";
        piece_symbol = "r";
    }
    return piece_symbol;
}
