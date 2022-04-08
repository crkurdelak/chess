#include "Board.h"
#include "Piece.h"

Board::Board() {

}

Square &Board::square_at(size_t rank, size_t file) const {
    return <#initializer#>;
}

bool Board::is_clear_rank(const Square &from, const Square &to) const {
    return false;
}

bool Board::is_clear_file(const Square &from, const Square &to) const {
    return false;
}

bool Board::is_clear_diag(const Square &from, const Square &to) const {
    return false;
}

Board::~Board() {

}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    return <#initializer#>;
}
