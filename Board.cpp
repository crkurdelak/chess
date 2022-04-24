/**
 * @file Board.cpp
 * @brief Implementation of the Board class.
 */

#include "Board.h"
#include "Piece.h"

Board::Board() {
    // rank
    for (int i = 0; i < SIZE; i++) {
        // file
        for (int j = 0; j < SIZE; j++) {
            Square* new_square = new Square(i, j);
            _squares[i][j] = new_square;
        }
    }
}


Square &Board::square_at(size_t rank, size_t file) const {
    return *_squares[rank][file];
}


Square &Board::square_at(const std::string &identifier) const {
    size_t file = 0;
    size_t rank = 0;
    std::string file_string = identifier.substr(0, 1);
    std::string rank_string = identifier.substr(1, 1);

    // translate chess notation to indices
    // first character is file
    if (file_string == "a") {
        file = 0;
    }
    else if (file_string == "b") {
        file = 1;
    }
    else if (file_string == "c") {
        file = 2;
    }
    else if (file_string == "d") {
        file = 3;
    }
    else if (file_string == "e") {
        file = 4;
    }
    else if (file_string == "f") {
        file = 5;
    }
    else if (file_string == "g") {
        file = 6;
    }
    else if (file_string == "h") {
        file = 7;
    }

    // second character is rank
    if (rank_string == "1") {
        rank = 7;
    }
    else if (rank_string == "2") {
        rank = 6;
    }
    else if (rank_string == "3") {
        rank = 5;
    }
    else if (rank_string == "4") {
        rank = 4;
    }
    else if (rank_string == "5") {
        rank = 3;
    }
    else if (rank_string == "6") {
        rank = 2;
    }
    else if (rank_string == "7") {
        rank = 1;
    }
    else if (rank_string == "8") {
        rank = 0;
    }

    // call other square_at method
    return this->square_at(rank, file);
}


bool Board::is_clear_rank(const Square &from, const Square &to) const {
    bool is_clear = true;
    size_t rank = from.rank();
    if (this->is_valid_rank(from, to)) {
        size_t i = from.file() + 1;
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
    if (this->is_valid_file(from, to)) {
        size_t i = from.rank() + 1;
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
    bool is_clear = true;
    if (this->is_valid_diag(from, to)) {
        size_t rank = from.rank() + 1;
        size_t file = from.file() + 1;
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
    return square.rank() >= 0
    && square.rank() < SIZE
    && square.file() >= 0
    && square.file() < SIZE;
}


bool Board::is_valid_rank(const Square &from, const Square &to) const {
    return is_in_bounds(from) && is_in_bounds(to) && from.rank() == to.rank();
}

bool Board::is_valid_file(const Square &from, const Square &to) const {
    return is_in_bounds(from) && is_in_bounds(to) && from.file() == to.file();
}

bool Board::is_valid_diag(const Square &from, const Square &to) const {
    const double EPSILON = 1e-10;
    double slope = (to.rank() * 1.0 - from.rank()) / (to.file() * 1.0 - from.file());
    return is_in_bounds(from)
           && is_in_bounds(to)
           && ((slope > 0
                && slope - 1 <= EPSILON)
           || (slope < 0
                && slope + 1 <= EPSILON));
}


std::ostream &operator<<(std::ostream &os, const Board &board) {
    // file labels
    os << "    a   b   c   d   e   f   g   h   " << std::endl;
    os << "  +---+---+---+---+---+---+---+---+" << std::endl;
    // output squares and dividers from bottom to top
    for (int i = 0; i < Board::SIZE;  i++) {
        for (int j = 0; j < Board::SIZE; j++) {
            if (j == 0) {
                // left rank label
                os << Board::SIZE - i;
            }
            // output _squares[i][j]
            os << " | " << board.square_at(i, j);
            if (j == Board::SIZE - 1) {
                // right rank label
                os << " | " << Board::SIZE - i << std::endl;
            }
        }
        //dividers
        os << "  +---+---+---+---+---+---+---+---+" << std::endl;
    }
    // file labels
    os << "    a   b   c   d   e   f   g   h   " << std::endl;

    return os;
}
