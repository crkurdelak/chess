//
// TODO comment
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H


#include <vector>
#include "Board.h"
#include "Piece.h"
#include "King.h"

class Player {
public:
    /**
     * TODO comment
     * @param color
     * @param board
     */
    Player(Piece::Color color, const Board& board);


    /**
     * TODO comment
     * @return
     */
    Piece::Color color() const;


    /**
     * TODO comment
     * @param from
     * @param to
     * @return
     */
    bool make_move(const std::string& from, const std::string& to);


    /**
     * TODO comment
     * @return
     */
    piece_value_t piece_value() const;


    /**
     * TODO comment
     */
    ~Player();

private:
    const Piece::Color _color;
    const Board& _board;
    std::vector<Piece*> _pieces;
    King* _king;
};


#endif //CHESS_PLAYER_H
