#ifndef PIECE_H
#define PIECE_H

#include <iostream>

// forward declaration of class
class Square;

// type alias
typedef unsigned int piece_value_t;

class Piece {
  public:
    /**
     * Pieces can be black or white.
     */
    enum struct Color {
        black, white
    };


    /**
     * @brief
     * @param color
     * @param location
     */
    Piece(const Piece::Color color, Square& location) : _color(color) {
        this->set_location(&location);
    }


    /**
     * @brief
     * @return
     */
    virtual piece_value_t value() const = 0;


    /**
     * @brief
     * @return
     */
    Piece::Color color() const;


    /**
     * @brief
     * @return
     */
    Square* location() const;


    /**
     * @brief
     * @param location
     */
    void set_location(Square* location);


    /**
     * @brief
     * @return
     */
    bool is_on_square() const;


    /**
     * @brief
     * @param location
     * @return
     */
    virtual bool can_move_to(const Square& location) const = 0;


    /**
     * @brief
     * @param location
     * @return
     */
    bool move_to(Square& location);


    /**
     * @brief
     * @return
     */
    virtual std::string str() const = 0;

  private:
    const Piece::Color _color;
    Square* _location = nullptr;
};


/**
 * @brief Outputs a Unicode character representing this piece.
 *
 * Calls the piece's str() method.
 *
 * @param os
 * @param piece
 * @return
 */
std::ostream& operator<<(std::ostream& os, const Piece& piece);

#endif
