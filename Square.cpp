#include "Square.h"
#include "Piece.h"

size_t Square::rank() const {
    return 0;
}


size_t Square::file() const {
    return 0;
}


bool Square::is_occupied() const {
    return false;
}


Piece *Square::occupant() const {
    return nullptr;
}


void Square::set_occupant(Piece *occupant) {

}


std::ostream &operator<<(std::ostream &os, const Square &square) {
    return <#initializer#>;
}
