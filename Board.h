/**
 * @file Board.h
 * @brief Declarations for the Board class.
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Square.h"


/**
 * @brief A class representing a chess board.
 */
class Board {
  public:
    // The number of ranks and files
    static const size_t SIZE = 8;


    /**
     * @brief Constructs a new board.
     *
     * Dynamically allocates 64 new squares and stores their addresses in the 8x8 _squares array.
     */
    Board();


    /**
     * @brief Returns the square at the given rank and file.
     * @param rank the rank of the square
     * @param file the file of the square
     * @return the square at the given rank and file
     */
    Square& square_at(size_t rank, size_t file) const;


    /**
     * TODO comment
     * @param identifier
     * @return
     */
    Square& square_at(const std::string& identifier) const;


    /**
     * TODO comment
     * @param from
     * @param to
     * @return
     */
    bool is_valid_rank(const Square& from, const Square& to) const;


    /**
     * TODO comment
     * @param from
     * @param to
     * @return
     */
    bool is_valid_file(const Square& from, const Square& to) const;


    /**
     * TODO comment
     * @param from
     * @param to
     * @return
     */
    bool is_valid_diag(const Square& from, const Square& to) const;


    /**
     * @brief Returns true if the given rank is clear.
     * @param from the starting square
     * @param to the ending square
     * @return true if the given rank is a valid rank and is clear; else return false
     */
    bool is_clear_rank(const Square& from, const Square& to) const;


    /**
     * @brief Returns true if the given file is clear.
     * @param from the starting square
     * @param to the ending square
     * @return true if the given file is a valid file and is clear; else return false
     */
    bool is_clear_file(const Square& from, const Square& to) const;


    /**
     * @brief Returns true if the given diagonal is clear.
     * @param from the starting square
     * @param to the ending square
     * @return true if the given diagonal is a valid diagonal and is clear; else return false
     */
    bool is_clear_diag(const Square& from, const Square& to) const;


    /**
     * A destructor for the board.
     *
     * Deletes all the squares dynamically allocated by the constructor
     */
    ~Board();

  private:
    Square* _squares[SIZE][SIZE] = {};

    /**
     * Returns true if the given square is within the bounds of the board.
     * @param square the square to check
     * @return true if the square is within the bounds of the board; else return false
     */
    static bool is_in_bounds(const Square &square) ;
};


/**
 * Sends the board to an output stream.
 *
 * Each square has to output itself.
 *
 * @param os the output stream
 * @param board the board to be output
 * @return the output stream
 */
std::ostream& operator<<(std::ostream& os, const Board& board);

#endif
