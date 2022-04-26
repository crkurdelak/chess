/**
 * @file Player.cpp
 * @brief Implementation of the Player class.
 */

#include "Player.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"

Player::Player(Piece::Color color, const Board &board) : _color(color), _board(board) {
    _pieces = std::vector<Piece*>();
    _king = nullptr;

    // set up all this player's pieces
    if (color == Piece::Color::black) {
        // create all the black pieces in the right places
        // pawns
        for (int i = 0; i < 7; i++) {
            _pieces.push_back(new Pawn(color, board.square_at(1, i)));
        }
        // rooks
        _pieces.push_back(new Rook(color, board.square_at(0, 0)));
        _pieces.push_back(new Rook(color, board.square_at(0, 7)));
        // knights
        _pieces.push_back(new Knight(color, board.square_at(0, 1)));
        _pieces.push_back(new Knight(color, board.square_at(0, 6)));
        // bishops
        _pieces.push_back(new Bishop(color, board.square_at(0, 2)));
        _pieces.push_back(new Bishop(color, board.square_at(0, 5)));
        // queen
        _pieces.push_back(new Queen(color, board.square_at(0, 3)));
        // king
        _king = new King(color, board.square_at(0, 4));
        _pieces.push_back(_king);

    }
    else {
        // create all the white pieces in the right places
        // pawns
        for (int i = 0; i < 7; i++) {
            _pieces.push_back(new Pawn(color, board.square_at(6, i)));
        }
        // rooks
        _pieces.push_back(new Rook(color, board.square_at(7, 0)));
        _pieces.push_back(new Rook(color, board.square_at(7, 7)));
        // knights
        _pieces.push_back(new Knight(color, board.square_at(7, 1)));
        _pieces.push_back(new Knight(color, board.square_at(7, 6)));
        // bishops
        _pieces.push_back(new Bishop(color, board.square_at(7, 2)));
        _pieces.push_back(new Bishop(color, board.square_at(7, 5)));
        // queen
        _pieces.push_back(new Queen(color, board.square_at(7, 3)));
        // king
        _king = new King(color, board.square_at(7, 4));
        _pieces.push_back(_king);
    }
}


Piece::Color Player::color() const {
    return _color;
}


bool Player::make_move(const std::string &from, const std::string &to) {
    Square from_sq = _board.square_at(from);
    Square to_sq = _board.square_at(to);
    auto my_piece = from_sq.occupant();
    bool result = false;

    if (my_piece->color() == _color) {
        if (to_sq.occupant() == nullptr || to_sq.occupant()->color() != _color) {
            if (my_piece->can_move_to(_board.square_at(to))) {
                if (my_piece->needs_clear_path()) {
                    if (_board.is_valid_file(from_sq, to_sq)) {
                        if (_board.is_clear_file(from_sq, to_sq)) {
                            my_piece->move_to(to_sq);
                            result = true;
                        }
                    } else if (_board.is_valid_rank(from_sq, to_sq)) {
                        if (_board.is_clear_rank(from_sq, to_sq)) {
                            my_piece->move_to(to_sq);
                            result = true;
                        }
                    } else if (_board.is_valid_diag(from_sq, to_sq)) {
                        if (_board.is_clear_diag(from_sq, to_sq)) {
                            my_piece->move_to(to_sq);
                            result = true;
                        }
                    }
                }
            }
        }
    }
    return result;
}


piece_value_t Player::piece_value() const {
    piece_value_t total_value = 0;
    for (auto piece : _pieces) {
        if (piece->location() != nullptr) {
            total_value += piece->value();
        }
    }
    return total_value;
}


Player::~Player() {
    for (auto piece : _pieces) {
        delete piece;
    }
}
