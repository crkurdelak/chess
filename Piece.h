/**
 * @file Piece.h
 * @brief Declarations for the Piece class.
 */

#ifndef PIECE_H
#define PIECE_H

#include <iostream>

// forward declaration of class
class Square;

// type alias
typedef unsigned int piece_value_t;


/**
 * @brief A class representing a chess piece.
 */
class Piece {
  public:
    /**
     * Pieces can be black or white.
     */
    enum struct Color {
        black, white
    };


    /**
     * @brief Creates a new piece with the given color and location
     * @param color the color of the piece
     * @param location the location of the piece
     */
    Piece(const Piece::Color color, Square& location) : _color(color) {
        this->set_location(&location);
    }


    /**
     * @brief Returns the value of this piece.
     * @return the value of this piece.
     */
    virtual piece_value_t value() const = 0;


    /**
     * @brief Returns the color of this piece.
     * @return the color of this piece
     */
    Piece::Color color() const;


    /**
     * @brief Returns the location of this piece.
     * @return the location of this piece
     */
    Square* location() const;


    /**
     * @brief Sets the location of this piece to the given location.
     * @param location the new location of this piece
     */
    void set_location(Square* location);


    /**
     * @brief Returns true if this piece is on a square.
     *
     * If a piece is not on a square, its location attribute will be a null pointer.
     *
     * @return true if this piece is on a square; else return false
     */
    bool is_on_square() const;


    /**
     * @brief Returns true if this piece can move to the given location.
     * @param location the location to test
     * @return true if this piece can move to the given location; else return false
     */
    virtual bool can_move_to(const Square& location) const = 0;


    /**
     * @brief Moves this piece to the given location, and captures any enemy piece occupying that
     * location.
     * @param location the new location
     * @return true if successful; else return false
     */
    virtual bool move_to(Square& location);


    /**
     * @brief Captures the previous occupant of this piece's current square.
     *
     * Sets this piece's location square that it is no longer occupied, and sets this piece's
     * location to nullptr.
     *
     * A piece can only capture a piece of the opposite color.
     */
    void capture();


    /**
     * @brief Returns a string representation of this piece.
     *
     * Each piece is represented by a Unicode character.
     *
     * @return a string representation of this piece
     */
    virtual std::string str() const = 0;


    /**
     *
     */
    virtual ~Piece() = default;


    /**
     * @brief Returns true if this piece needs a clear path in order to move.
     * @return true if this piece needs a clear path; else returns false
     */
    virtual bool needs_clear_path() const = 0;

private:
    const Piece::Color _color;
    Square* _location = nullptr;
};


/**
 * @brief Outputs a Unicode character representing this piece.
 *
 * Calls the piece's str() method.
 *
 * @param os the output stream
 * @param piece the piece to be output
 * @return the output stream
 */
std::ostream& operator<<(std::ostream& os, const Piece& piece);

#endif
