#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Square.h"

class Board {
  public:
    static const size_t SIZE = 8;

    Board();

    Square& square_at(size_t rank, size_t file) const;

    bool is_clear_rank(const Square& from, const Square& to) const;
    bool is_clear_file(const Square& from, const Square& to) const;
    bool is_clear_diag(const Square& from, const Square& to) const;

    ~Board();

  private:
    Square* _squares[SIZE][SIZE] = {};
};

std::ostream& operator<<(std::ostream& os, const Board& board);

#endif
