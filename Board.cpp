#include "Board.h"
#include "Piece.h"

Board::Board() {
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
    return *_squares[rank][file];
}


bool Board::is_clear_rank(const Square &from, const Square &to) const {
    bool is_clear = true;
    size_t rank = from.rank();
    if (is_in_bounds(from) && is_in_bounds(to) && rank == to.rank()) {
        size_t i = from.file();
        while (i < to.file() && is_clear) {
            if (_squares[rank][i]->is_occupied()) {
                is_clear = false;
                i++;
            }
        }
    }
    else {
        is_clear = false;
    }
    return is_clear;
}


bool Board::is_clear_file(const Square &from, const Square &to) const {
    bool is_clear = true;
    size_t file = from.file();
    if (is_in_bounds(from) && is_in_bounds(to) && file == to.file()) {
        size_t i = from.rank();
        while (i < to.rank() && is_clear) {
            if (_squares[i][file]->is_occupied()) {
                is_clear = false;
                i++;
            }
        }
    }
    else {
        is_clear = false;
    }
    return is_clear;
}


bool Board::is_clear_diag(const Square &from, const Square &to) const {
    const double EPSILON = 1e-10;
    bool is_clear = true;
    double slope = (to.rank() * 1.0 - from.rank()) / (to.file() * 1.0 - from.file());
    if (is_in_bounds(from) && is_in_bounds(to) && (slope - 1 <= EPSILON || slope + 1 <= EPSILON)) {
        size_t rank = from.rank();
        size_t file = from.file();
        while (rank < to.rank() && file < to.file() && is_clear) {
            if (_squares[rank][file]->is_occupied()) {
                is_clear = false;
                rank++;
                file++;
            }
        }
    }
    else {
        is_clear = false;
    }
    return is_clear;
}


Board::~Board() {
    // rank
    for (int i = 0; i < SIZE; i++) {
        // file
        for (int j = 0; j < SIZE; j++) {
            delete _squares[i][j];
        }
    }
}

bool Board::is_in_bounds(const Square &square) {
    return square.rank() >= 0 && square.rank() < SIZE && square.file() >= 0 && square.file() < SIZE;
}


std::ostream &operator<<(std::ostream &os, const Board &board) {
    // for each rank
    // for each file
    // draw line
    // output square
    // draw line
    return os;
}
