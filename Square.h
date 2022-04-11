#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Piece.h"

class Square {
  public:
    /**
     * @brief Creates a new square.
     * @param rank the rank of the new square
     * @param file the file of the new square
     */
    Square(size_t rank, size_t file) : _rank(rank), _file(file) { }


    /**
     * @brief Returns the rank of this square.
     * @return the rank of this square
     */
    size_t rank() const;


    /**
     * @brief Returns the file of this square.
     * @return the file of this square
     */
    size_t file() const;


    /**
     * @brief Returns true if this square is occupied.
     * @return true if this square is occupied; else returns false
     */
    bool is_occupied() const;


    /**
     * @brief Returns a pointer to the occupant of this square.
     * @return a pointer to the occupant of this square
     */
    Piece* occupant() const;


  private:
    /**
     * @brief Sets the occupant of this square to a new value.
     * @param occupant the new occupant of this square
     */
    void set_occupant(Piece* occupant);


    const size_t _rank;
    const size_t _file;
    Piece* _occupant = nullptr;


    /**
     * Allow this method of the Piece class to access the private members of the class so that
     * it can set the occupant of the square.
     */
    friend void Piece::set_location(Square* location);
};


/**
 * @brief Outputs a square and its occupant if it has one.
 *
 * If the square has  no occupant, return a single space character instead.
 *
 * @param os the output stream
 * @param square the square to be output
 * @return the output stream
 */
std::ostream& operator<<(std::ostream& os, const Square& square);

#endif
