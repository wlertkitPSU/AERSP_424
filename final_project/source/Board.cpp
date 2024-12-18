#include "Board.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

// Constructor
Board::Board() : _squares(_rows, vector<Square>(_cols)) 
{
    init_pieces();
    init_board();
}

// Destructor
Board::~Board()
{
    for (Piece *piece : _white) delete piece;
    for (Piece *piece : _black) delete piece;
}

// Initialize all pieces
void Board::init_pieces()
{
    int col = 0;

    // Initial positions for major pieces
    vector<pair<Piece *, Piece *>> major_pieces = {
        {new Rook(WHITE, {0, col}), new Rook(BLACK, {7, col++})},
        {new Knight(WHITE, {0, col}), new Knight(BLACK, {7, col++})},
        {new Bishop(WHITE, {0, col}), new Bishop(BLACK, {7, col++})},
        {new Queen(WHITE, {0, col}), new Queen(BLACK, {7, col++})},
        {new King(WHITE, {0, col}), new King(BLACK, {7, col++})},
        {new Bishop(WHITE, {0, col}), new Bishop(BLACK, {7, col++})},
        {new Knight(WHITE, {0, col}), new Knight(BLACK, {7, col++})},
        {new Rook(WHITE, {0, col}), new Rook(BLACK, {7, col++})}};

    for (const auto &pair : major_pieces)
    {
        _white.push_back(pair.first);
        _black.push_back(pair.second);
    }

    // Pawns
    for (int i = 0; i < _cols; ++i)
    {
        _white.push_back(new Pawn(WHITE, {1, i}));
        _black.push_back(new Pawn(BLACK, {6, i}));
    }
}

// Place pieces on the board
void Board::init_board()
{
    for (Piece *piece : _white)
    {
        pair<int, int> loc = piece->location();
        _squares[loc.first][loc.second].set_piece(piece, loc);
    }

    for (Piece *piece : _black)
    {
        pair<int, int> loc = piece->location();
        _squares[loc.first][loc.second].set_piece(piece, loc);
    }
}

// Prints out the current board
void Board::print_board(ostream &out) const
{
    // Prints the top border
    out << "  _______________________________________________________" << endl;

    // Prints everything but the bottom letter coordinates
    for (int r = _rows - 1; r >= 0; r--)
    {
        // Prints the upper empty space of the squares and the number coordinate associated with that row
        out << " |      |      |      |      |      |      |      |      |\n"
            << r + 1 << "|";

        // Prints the names of the pieces in the squares of this row
        for (int c = 0; c < _cols; c++)
        {
            out << " ";

            // If this square contains a piece --> print its color and name
            if (_squares[r][c].occupied())
            {
                out << " " << _squares[r][c].piece()->fullName();
            }

            // If this square doesn't contain a piece --> print two blank spaces
            else
            {
                out << "   ";
            }

            out << "  |";
        }

        // Prints the bottom portion of each square
        out << "\n"
            << " |______|______|______|______|______|______|______|______|" << endl;
    }

    // Prints the bottom letter coordinates
    out << "    a      b      c      d      e      f      g      h" << endl;
}

// Playing a game between two people
void Board::play_user()
{
    string command;              // Entire line inputted by user as a command. Parsed for max of two potential separate strings later.
    string turn_color = "White"; // Color whose turn it currently is
    string off_color = "Black";  // Color whose turn is next
    bool draw_agree = false;     // True if one player attempts to declare a draw

    // Main game loop (will loop forever unless one player quits, both players draw, or one player is put in checkmate and loses)
    for (;;)
    {
        print_board(std::cout);

        std::cout << "\nIt is " << turn_color << "'s turn.\n"
                  << "Please input a command: ";
        getline(cin, command);
        if (command.empty())
        {
            continue;
        }
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        istringstream iss(command);
        vector<string> commands{istream_iterator<string>{iss}, istream_iterator<string>{}};

        string first = commands[0];

        // If first player offers a draw
        if (draw_agree)
        {
            // Second player has agreed to a draw, and both players forfeit the game.
            if (first == "draw")
            {
                std::cout << "\nBoth sides have agreed to a draw.\n"
                          << "Nobody wins." << endl;

                return;
            }

            // Second player has disagreed to a draw, and the first player proceeds their turn as if nothing happened.
            else
            {
                std::cout << "\n"
                          << turn_color << " disagreed to a draw.\n"
                          << off_color << " will proceed their turn as normal." << endl;

                draw_agree = false;
                string temp = turn_color;
                turn_color = off_color;
                off_color = temp;

                continue;
            }
        }

        // Exit chess program or offer draw
        if (first == "quit" || first == "resign")
        {
            std::cout << "\n"
                      << turn_color << " has given up.\n"
                      << off_color << " wins!" << endl;

            return;
        }

        else if (first == "draw" || first == "stalemate")
        {
            draw_agree = true;

            cout << "\n"
                 << turn_color << " has declared a draw.\n"
                 << "If " << off_color << " also declares a draw, the game will end in a draw." << endl;
            string temp = turn_color;
            turn_color = off_color;
            off_color = temp;
            continue;
        }

        // If the command is two sets of coordinates
        if (commands.size() > 1)
        {
            string second = commands[1];
            int move_result = move(toupper(turn_color[0]), first, second);

            // If the piece was not moved for some reason
            if (move_result == BAD)
            {
                continue;
            }

            // The enemy is in check and needs to secure their king
            else if (move_result == CHECK)
            {
                print_board(std::cout);

                std::cout << "\n"
                          << off_color << " is in check.\n";
            }

            // The enemy is in checkmate and has lost the game
            else if (move_result == CHECKMATE)
            {
                print_board(std::cout);

                std::cout << "\n"
                          << off_color << " is in checkmate.\n"
                          << turn_color << " wins!" << endl;

                return;
            }

            // The enemy is in stalemate and nobody wins the game
            else if (move_result == STALEMATE)
            {
                print_board(std::cout);

                std::cout << "\n"
                          << off_color << " is in stalemate.\n"
                          << "Nobody wins." << endl;

                return;
            }
        }

        // If there is an invalid command
        else
        {
            std::cout << "\nInvalid command." << endl;

            continue;
        }

        // Necessary steps to take in order to change the turn order
        string temp = turn_color;
        turn_color = off_color;
        off_color = temp;
    }
}

// Moves pieces on the board
int Board::move(char color, string first, string second)
{
    // Checks that the coordinates given are within the boundaries of the 8x8 chess board
    if (!checkMoveCoords(first[0], first[1]) || !checkMoveCoords(second[0], second[1]))
    {
        std::cout << "\nInvalid command." << endl;

        return BAD;
    }

    // Convert Ascii to coords
    // a = 97, b = 98, ...
    // '1' = 49, '2' = 50, ...
    Square *move_from = &_squares[first[1] - 49][first[0] - 97];

    // If there is no piece on the square
    if (!move_from->occupied())
    {
        std::cout << "\nThere is no piece on that square." << endl;

        return BAD;
    }

    // If there is an enemy piece on the square
    if (move_from->piece()->color() != color)
    {
        std::cout << "\nThat's not your piece." << endl;

        return BAD;
    }

    // From now on assuming there is a piece on the square
    // pair<int, int> move_from_loc = {first[1] - 49, first[0] - 97};
    pair<int, int> move_to_loc = {second[1] - 49, second[0] - 97};
    vector<pair<int, int>> move_to_list = move_from->piece()->moveCheck(move_to_loc);

    // The last square in the list is the square the player is trying to move their piece to
    // Checks to confirm that the player has made a valid choice
    if (move_to_list.empty() || move_to_list.back() != move_to_loc)
    {
        std::cout << "\nThat piece's movement doesn't allow it to reach that square." << endl;

        return BAD;
    }

    // Checks the entire list of squares in the direction the piece is being moved ensuring that it
    // isn't being blocked by any other piece
    for (auto it = move_to_list.begin(); it != move_to_list.end() - 1; ++it)
    {
        if (_squares[(*it).first][(*it).second].occupied())
        {
            std::cout << "\nThat piece is blocked from reaching that square." << endl;

            return BAD;
        }
    }

    Square *move_to = &_squares[move_to_loc.first][move_to_loc.second];

    // If the square is occupied by another piece
    if (move_to->occupied())
    {
        // If a pawn is being moved forward --> means it's not going to capture another piece
        if (move_from->piece()->name() == PAWN && move_from->piece()->location().second == move_to_loc.second)
        {
            // If the pawn is trying to move to a square occupied by a friendly piece
            if (move_to->piece()->color() == color)
            {
                std::cout << "\nThat piece is blocked from reaching that square." << endl;

                return BAD;
            }

            // If the pawn is trying to capture an enemy piece in front of it
            std::cout << "\nA pawn can only capture another piece by moving forward diagonally one space." << endl;

            return BAD;
        }

        // If a piece is trying to capture a friendly piece
        if (move_to->piece()->color() == color)
        {
            std::cout << "\nYou cannot capture your own piece." << endl;

            return BAD;
        }
        // If a piece is trying to capture an enemy piece
        else
        {
            // This is an invalid move (vulnerable king)
            if (is_legal(move_from->piece(), move_to->piece(), move_to_loc))
            {
                std::cout << "\nTrying to capture that piece would render your king vulnerable to capture." << endl;

                return BAD;
            }

            Piece &move_to_piece = *move_to->piece();

            string temp_name = move_to->piece()->fullName();

            // If piece being captured is white
            if (move_to->piece()->color() == WHITE)
            {
                // Removing the piece from the list of pieces we have a destructor for so need
                // to remove it from the vector and delete it
                auto to_remove = find(_white.begin(), _white.end(), move_to_piece);
                delete *to_remove;
                _white.erase(to_remove);
            }

            // If piece being captured is black
            else
            {
                // Removing the piece from the list of pieces we have a destructor for so need
                // to remove it from the vector and delete it
                auto to_remove = find(_black.begin(), _black.end(), move_to_piece);
                delete *to_remove;
                _black.erase(to_remove);
            }

            std::cout << "\n"
                      << move_from->piece()->fullName() << " captured " << temp_name << endl;
            move_to->remove_piece();
        }
    }

    // If the square the piece is trying to move to isn't occupied by another piece
    else
    {
        // If a pawn is being moved to an empty square, it has to be in front of it
        // Pawn can only be moved diagonally one space if the space is occupied by an enemy piece
        if (move_from->piece()->name() == PAWN && move_from->piece()->location().second != move_to_loc.second)
        {
            std::cout << "\nA pawn can only capture another piece by moving forward diagonally one space." << endl;

            return BAD;
        }

        // This is an invalid move (vulnerable king)
        if (is_legal(move_from->piece(), move_to->piece(), move_to_loc))
        {
            std::cout << "\nIllegal move, you are in check." << endl;

            return BAD;
        }
    }

    // Sets the new square to contain this piece
    move_to->set_piece(move_from->piece(), move_to_loc);
    move_from->remove_piece();

    return is_check(move_to->piece());
}

// Checking to see if king is vulnerable
bool Board::is_legal(Piece *move_from_piece, Piece *move_to_piece, pair<int, int> move_to_loc)
{
    // If piece being moved is white
    if (move_from_piece->color() == WHITE)
    {
        // Iterates through every black piece on the board
        for (auto it = _black.begin(); it != _black.end(); ++it)
        {
            // Will be NULL when is_legal() is called and there is no piece on the square being moved to
            if (move_to_piece)
            {
                // Ensures that the piece being moved to isn't the one being captured
                if (*it == move_to_piece)
                {
                    continue;
                }
            }

            vector<vector<pair<int, int>>> all_move_to_list = (*it)->allMoveCheck(); // All possible squares the piece can move to

            // Iterates through the coordinates of every square the piece can potentially move to
            for (auto ita = all_move_to_list.begin(); ita != all_move_to_list.end(); ++ita)
            {
                for (auto itb = (*ita).begin(); itb != (*ita).end(); ++itb)
                {
                    pair<int, int> location = {(*itb).first, (*itb).second};      // Coordinates of the square being moved to
                    Square *move_to = &_squares[location.first][location.second]; // Square being moved to

                    // Means this piece is capable of capturing the piece we just moved
                    if (location == move_to_loc)
                    {
                        // Piece is a pawn and it hasn't changed columns --> it's trying to capture a piece
                        // without moving diagonally --> invalid
                        if ((*it)->name() == PAWN && (*it)->location().second == location.second)
                        {
                            break;
                        }

                        // If the piece the player moved is a king and this new piece is capable of capturing it
                        if (move_from_piece->name() == KING)
                        {
                            return true;
                        }

                        break;
                    }

                    // If the location of our new piece is the same as the original location of the piece that might be moved
                    if (location == move_from_piece->location())
                    {
                        continue;
                    }

                    // If the square being moved to is occupied
                    if (move_to->occupied())
                    {
                        // Pawn can only capture diagonally
                        if ((*it)->name() == PAWN && (*it)->location().second == location.second)
                        {
                            break;
                        }

                        // If the piece that occupies this space is the enemy player's king
                        if (move_to->piece()->fullName() == "WK")
                        {
                            return true;
                        }

                        break;
                    }
                }
            }
        }
    }

    // Piece being moved is black
    else
    {
        // Iterate through every white piece on the board
        for (auto it = _white.begin(); it != _white.end(); ++it)
        {
            // Will be NULL when is_legal() is called and there is no piece on the square being moved to
            if (move_to_piece)
            {
                // Ensures that the piece being moved to isn't the one being captured
                if (*it == move_to_piece)
                {
                    continue;
                }
            }

            vector<vector<pair<int, int>>> all_move_to_list = (*it)->allMoveCheck(); // All possible squares that piece can move to

            // Iterates through the coordinates of every square the piece can potentially move to
            for (auto ita = all_move_to_list.begin(); ita != all_move_to_list.end(); ++ita)
            {
                for (auto itb = (*ita).begin(); itb != (*ita).end(); ++itb)
                {
                    pair<int, int> location = {(*itb).first, (*itb).second};      // Coordinates of the square being moved to
                    Square *move_to = &_squares[location.first][location.second]; // Square being moved to

                    // Check if square being moved to is the same square the original piece moved to
                    if (location == move_to_loc)
                    {
                        // Pawn captures diagonally only
                        if ((*it)->name() == PAWN && (*it)->location().second == location.second)
                        {
                            break;
                        }

                        // If the piece the player moved is a king and this new piece is capable of capturing it
                        if (move_from_piece->name() == KING)
                        {
                            return true;
                        }

                        break;
                    }

                    // If the location of our new piece is the same as the original location of the piece that might be moved
                    if (location == move_from_piece->location())
                    {
                        continue;
                    }

                    // If the square being moved to is occupied
                    if (move_to->occupied())
                    {
                        // Pawn can only capture diagonally
                        if ((*it)->name() == PAWN && (*it)->location().second == location.second)
                        {
                            break;
                        }

                        // If the piece that occupies this space is the enemy player's king
                        if (move_to->piece()->fullName() == "BK")
                        {
                            return true;
                        }

                        break;
                    }
                }
            }
        }
    }

    return false;
}

// Checks for checkmate
bool Board::is_checkmate(char color)
{
    // Determine the player's pieces and king
    const auto &player_pieces = (color == WHITE) ? _white : _black;

    // Locate the player's king
    Piece *king = nullptr;
    for (Piece *piece : player_pieces)
    {
        if (piece->name() == KING)
        {
            king = piece;
            break;
        }
    }

    // If no king is found (shouldn't happen), return false
    if (!king) return false;

    // Check if the king is currently in check
    bool king_in_check = is_legal(king, nullptr, king->location());
    if (!king_in_check)
        return false; // Not checkmate since king is not under threat

    // Iterate through all the player's pieces to see if any legal move can resolve the check
    for (Piece *piece : player_pieces)
    {
        vector<vector<pair<int, int>>> all_moves = piece->allMoveCheck();

        for (const auto &path : all_moves)
        {
            for (const auto &move : path)
            {
                pair<int, int> original_loc = piece->location();
                Square &start_square = _squares[original_loc.first][original_loc.second];
                Square &target_square = _squares[move.first][move.second];
                Piece *captured_piece = target_square.piece();

                // Simulate the move
                target_square.set_piece(piece, move);
                start_square.remove_piece();

                // Check if the move resolves the check
                bool still_in_check = is_legal(king, nullptr, king->location());

                // Undo the move
                start_square.set_piece(piece, original_loc);
                target_square.set_piece(captured_piece, move);

                // If the king is no longer in check, it's not checkmate
                if (!still_in_check)
                    return false;
            }
        }
    }

    // No valid move resolved the check -> it's checkmate
    return true;
}

// Checks enemy's status
int Board::is_check(Piece *move_from_piece)
{
    vector<vector<pair<int, int>>> check_list = move_from_piece->allMoveCheck();

    // If piece that was moved was white
    if (move_from_piece->color() == WHITE)
    {
        for (auto it = check_list.begin(); it != check_list.end(); ++it)
        {
            for (auto ita = (*it).begin(); ita != (*it).end(); ++ita)
            {
                pair<int, int> location = {(*ita).first, (*ita).second};
                Square *move_to_square = &_squares[location.first][location.second];

                if (move_to_square->occupied())
                {
                    if (move_from_piece->name() == PAWN && move_from_piece->location().second == location.second)
                    {
                        break;
                    }

                    if (move_to_square->piece()->fullName() == "BK")
                    {
                        if (is_checkmate(WHITE))
                        {
                            return CHECKMATE;
                        }

                        return CHECK;
                    }

                    break;
                }
            }
        }
    }

    // If piece that was moved was black
    else
    {
        for (auto it = check_list.begin(); it != check_list.end(); ++it)
        {
            for (auto ita = (*it).begin(); ita != (*it).end(); ++ita)
            {
                pair<int, int> location = {(*ita).first, (*ita).second};
                Square *move_to_square = &_squares[location.first][location.second];

                if (move_to_square->occupied())
                {
                    if (move_from_piece->name() == PAWN && move_from_piece->location().second == location.second)
                    {
                        break;
                    }

                    if (move_to_square->piece()->fullName() == "WK")
                    {
                        if (is_checkmate(BLACK))
                        {
                            return CHECKMATE;
                        }

                        return CHECK;
                    }

                    break;
                }
            }
        }
    }

    // If the enemy player isn't in check but cannot make any valid moves --> stalemate and game ends in a draw
    if (is_checkmate(move_from_piece->color()))
    {
        return STALEMATE;
    }

    // The enemy player isn't in check, checkmate, or stalemate
    return GOOD;
}

// Checks move bounds
bool checkMoveCoords(char first, char second)
{
    if (first >= 'a' && first <= 'h' && second >= '1' && second <= '8')
    {
        return true;
    }

    return false;
}