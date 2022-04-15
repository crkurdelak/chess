#include "Bishop.h"

piece_value_t Bishop::value() const {
    return VALUE;
}

bool Bishop::can_move_to(const Square &location) const {
    bool result = false;
    size_t slope = (location.rank() - this -> location().rank()) / (location.file() - this ->
            location().file());
    if (slope == 1 || slope == -1) {
        result = true;
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
