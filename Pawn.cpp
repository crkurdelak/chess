#include "Pawn.h"
#include "Square.h"

piece_value_t Pawn::value() const {
    return 1;
}

bool Pawn::can_move_to(const Square &location) const {
    bool result = false;
    if (&location != this -> location()
    && location.rank() == this -> location()->rank() + 1
    && location.file() == this -> location() ->file()) {
        result = true;
    }
    return result;
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
