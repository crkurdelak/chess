#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Piece.h"

class Square {
  public:
    /**
     * @brief
     * @param rank
     * @param file
     */
    Square(size_t rank, size_t file) : _rank(rank), _file(file) { }


    /**
     * @brief
     * @return
     */
    size_t rank() const;


    /**
     * @brief
     * @return
     */
    size_t file() const;


    /**
     * @brief
     * @return
     */
    bool is_occupied() const;


    /**
     * @brief
     * @return
     */
    Piece* occupant() const;


  private:
    /**
     * @brief
     * @param occupant
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
 * @brief Outputs this square and its occupant if it has one.
 * @param os
 * @param square
 * @return
 */
std::ostream& operator<<(std::ostream& os, const Square& square);

#endif
