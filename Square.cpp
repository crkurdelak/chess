#include "Square.h"
#include "Piece.h"

size_t Square::rank() const {
    return _rank;
}


size_t Square::file() const {
    return _file;
}


bool Square::is_occupied() const {
    bool result;
    if (_occupant == nullptr) {
        result = false;
    }
    else {
        result = true;
    }
    return result;
}


Piece *Square::occupant() const {
    return _occupant;
}


void Square::set_occupant(Piece *occupant) {
    _occupant = occupant;
}


std::ostream &operator<<(std::ostream &os, const Square &square) {
    if (!square.is_occupied()) {
        os << " ";
    }
    else {
        Piece* occupant = square.occupant();
        std::string occupant_string = occupant->str();
        os << square.occupant()->str();
    }
    return os;
}
