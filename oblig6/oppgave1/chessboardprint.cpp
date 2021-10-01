#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoardPrint {
public: 
    ChessBoardPrint(ChessBoard &board) {
        board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
            cout << piece.type() << " is being removed from " << square << endl;
        };
        board.on_lost_game = [](ChessBoard::Color color) {
            string winner = color == ChessBoard::Color::WHITE ? "Black" : "White";
            cout << winner << " won the game" << endl;
        };
        board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        board.on_piece_move_missing = [](const string &square) {
            cout << "no piece at " << square << endl;
        };
        //here we add "&" to referance list for this lamda function so that we can access other methods from the
        //ChessBoardPrint object
        board.after_piece_move = [&](const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares) {
            cout << " +----+----+----+----+----+----+----+----+" << endl;
            for(int x = 0; x < squares.size(); x++) {
                cout << " | ";
                for(int y = 0; y < squares[0].size(); y++) {
                cout << get_cell(x, y, squares) << " | ";
                } 
                cout << endl << " +----+----+----+----+----+----+----+----+" << endl;
            }
        };
    }
    
private:
    string get_cell(int x, int y, const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares) const{
        auto &piece = squares[x][y];
        return (piece) ? piece->piece_char() : "  ";
    }
};