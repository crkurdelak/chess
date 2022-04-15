#include "Rook.h"

piece_value_t Rook::value() const {
    return VALUE;
}

bool Rook::can_move_to(const Square &location) const {
    bool  result = false;
    if(location.file() == this -> location().file || location.rank() == this -> location().rank) {
        result = true;
    }
    return result;
}

std::string Rook::str() const {
    std::string piece_symbol;
    if (this -> color() == Piece::Color::black) {
        piece_symbol = "♜";
    }
    else {
        piece_symbol = "♖";
    }
    return piece_symbol;
}
