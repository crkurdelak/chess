/**
 * @file Player.cpp
 * @brief Implementation of the Player class.
 */

#include "Player.h"

Player::Player(Piece::Color color, const Board &board) {
    // TODO implement Player ctor
}

Piece::Color Player::color() const {
    // TODO implement Player::color
    return Piece::Color::black;
}

bool Player::make_move(const std::string &from, const std::string &to) {
    // TODO implement make_move
    return false;
}

piece_value_t Player::piece_value() const {
    // TODO implement Player::piece_value
    return 0;
}

Player::~Player() {
    // TODO implement destructor
}
