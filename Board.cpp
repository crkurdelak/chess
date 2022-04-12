#include "Board.h"
#include "Piece.h"

Board::Board() {
    // for each cell in array, make a new square and store a pointer to it in there

    // rank
    for (int i = 0; i < SIZE; i++) {
        // file
        for (int j = 0; j < SIZE; j++) {
            Square new_square = * new Square(i, j);
            _squares[i][j] = &new_square;
        }
    }
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
