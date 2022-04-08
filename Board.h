#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Square.h"

class Board {
  public:
    static const size_t SIZE = 8;


    /**
     * @brief
     *
     * Allocate squares
     */
    Board();


    /**
     * @brief
     * @param rank
     * @param file
     * @return
     */
    Square& square_at(size_t rank, size_t file) const;


    /**
     * @brief Returns true if the given rank is clear.
     * @param from
     * @param to
     * @return true if the given rank is a valid rank and is clear; else return false
     */
    bool is_clear_rank(const Square& from, const Square& to) const;


    /**
     * @brief
     * @param from
     * @param to
     * @return
     */
    bool is_clear_file(const Square& from, const Square& to) const;


    /**
     *
     * @param from
     * @param to
     * @return
     */
    bool is_clear_diag(const Square& from, const Square& to) const;


    /**
     *
     *
     * Delete all squares you allocated
     */
    ~Board();

  private:
    Square* _squares[SIZE][SIZE] = {};
};


/**
 * Sends the board to an output stream.
 * @param os
 * @param board
 * @return
 */
std::ostream& operator<<(std::ostream& os, const Board& board);

#endif
