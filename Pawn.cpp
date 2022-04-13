#include "Pawn.h"

piece_value_t Pawn::value() const {
    return VALUE;
}

bool Pawn::can_move_to(const Square &location) const {
    return false;
}

std::string Pawn::str() const {
    std::string piece_symbol;
    if (this -> color() == Piece::Color::black) {
        piece_symbol = "♟";
    }
    else {
        piece_symbol = "♙";
    }
    return piece_symbol;
}
