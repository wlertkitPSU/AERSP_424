#include "Board.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

Board::Board() : _rows(8), _cols(8), _squares(8, vector<Square>(8, Square()))
{
    init_pieces();
    init_board();
}

Board::~Board()
{
    // Deletes white pieces
    for (auto it = _white.begin(); it != _white.end(); ++it)
    {
        delete *it;
    }

    // Deletes black pieces
    for (auto it = _black.begin(); it != _black.end(); ++it)
    {
        delete *it;
    }
}

// Creating the correct number of pieces on the board
void Board::init_pieces()
{
    int i = 0;

    _white.push_back(new Rook(WHITE, {0, i}));      
    _white.push_back(new Knight(WHITE, {0, i}));    
    _white.push_back(new Bishop(WHITE, {0, i}));    
    _white.push_back(new Queen(WHITE, {0, i}));     
    _white.push_back(new King(WHITE, {0, i}));      
    _white.push_back(new Bishop(WHITE, {0, i}));    
    _white.push_back(new Knight(WHITE, {0, i}));    
    _white.push_back(new Rook(WHITE, {0, i}));      

    _black.push_back(new Rook(BLACK, {7, i++}));
    _black.push_back(new Knight(BLACK, {7, i++}));
    _black.push_back(new Bishop(BLACK, {7, i++}));
    _black.push_back(new Queen(BLACK, {7, i++}));
    _black.push_back(new King(BLACK, {7, i++}));
    _black.push_back(new Bishop(BLACK, {7, i++}));
    _black.push_back(new Knight(BLACK, {7, i++}));
    _black.push_back(new Rook(BLACK, {7, i++}));

    for (i = 0; i < _cols; i++)
    {
        _white.push_back(new Pawn(WHITE, {1, i}));
        _black.push_back(new Pawn(BLACK, {6, i}));
    }
}

// Places pieces in correct initial positions
void Board::init_board()
{
    for (int c = 0; c < _cols; c++)
    {
        _squares[0][c].set_piece(_white[c], {0, c});
        _squares[1][c].set_piece(_white[c + _cols], {1, c});
        _squares[7][c].set_piece(_black[c], {7, c});
        _squares[6][c].set_piece(_black[c + _cols], {6, c});
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
    pair<int, int> move_from_loc = {first[1] - 49, first[0] - 97};
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
            if (is_suicide(move_from->piece(), move_to->piece(), move_to_loc))
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
                _white_captured.push_back(move_to->piece()->name());
                auto to_remove = find(_white.begin(), _white.end(), move_to_piece);
                delete *to_remove;
                _white.erase(to_remove);
            }

            // If piece being captured is black
            else
            {
                // Removing the piece from the list of pieces we have a destructor for so need
                // to remove it from the vector and delete it
                _black_captured.push_back(move_to->piece()->name());
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
        if (is_suicide(move_from->piece(), move_to->piece(), move_to_loc))
        {
            std::cout << "\nMoving that piece there would render your king vulnerable to capture." << endl;
            
            return BAD;
        }
    }

    // Sets the new square to contain this piece
    move_to->set_piece(move_from->piece(), move_to_loc);
    move_from->remove_piece();

    return is_check(move_to->piece());
}

// Checking to see if king is vulnerable
bool Board::is_suicide(Piece *move_from_piece, Piece *move_to_piece, pair<int, int> move_to_loc)
{
    // If piece being moved is white
    if (move_from_piece->color() == WHITE)
    {
        // Iterates through every black piece on the board
        for (auto it = _black.begin(); it != _black.end(); ++it)
        {
            // Will be NULL when is_suicide() is called and there is no piece on the square being moved to
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
            // Will be NULL when is_suicide() is called and there is no piece on the square being moved to
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
    // Piece potentially in checkmate is white
    if (color == BLACK)
    {
        // Iterates through every white piece on the board
        for (auto it = _white.begin(); it != _white.end(); ++it)
        {
            vector<vector<pair<int, int>>> all_move_to_list = (*it)->allMoveCheck(); // List of the potential squares a piece can move to

            // Iterates through the coordinates of every potential square this piece can move to
            for (auto ita = all_move_to_list.begin(); ita != all_move_to_list.end(); ++ita)
            {
                for (auto itb = (*ita).begin(); itb != (*ita).end(); ++itb)
                {
                    pair<int, int> location = {(*itb).first, (*itb).second};      // Location of square being moved to
                    Square *move_to = &_squares[location.first][location.second]; // Square being moved to

                    // If piece hits a square with another piece in it
                    if (move_to->occupied())
                    {
                        // If friendly piece can't move to that square or beyond it
                        // Checks if piece is a pawn and attempting to capture an enemy piece in front of it
                        if (move_to->piece()->color() == WHITE || ((*it)->name() == PAWN && (*it)->location().second == location.second))
                        {
                            break;
                        }

                        // If piece hits an enemy piece checks for checkmate based on new piece's location and the fact that particular
                        // enemy piece will be captured
                        if (!is_suicide(*it, move_to->piece(), location))
                        {
                            return false;
                        }
                    }

                    // If piece hits an empty square
                    else
                    {
                        // If piece is a pawn and attempting to move diagonally without capturing an enemy piece
                        if ((*it)->name() == PAWN && (*it)->location().second != location.second)
                        {
                            break;
                        }

                        // Check for checkmate based on new piece's location
                        if (!is_suicide(*it, NULL, location))
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }

    // Piece potentially in checkmate is black
    else
    {
        // Iterates through every black piece on the board
        for (auto it = _black.begin(); it != _black.end(); ++it)
        {
            vector<vector<pair<int, int>>> all_move_to_list = (*it)->allMoveCheck(); // A list of the potential squares a piece can move to

            // Iterates through the coordinates of every potential square this piece can move to
            for (auto ita = all_move_to_list.begin(); ita != all_move_to_list.end(); ++ita)
            {
                for (auto itb = (*ita).begin(); itb != (*ita).end(); ++itb)
                {
                    pair<int, int> location = {(*itb).first, (*itb).second};      // Location of square being moved to
                    Square *move_to = &_squares[location.first][location.second]; // Square being moved to

                    // If piece hits a square with another piece in it
                    if (move_to->occupied())
                    {
                        // If friendly piece it can't move to that square or beyond it
                        // Checks if piece is a pawn and attempting to capture an enemy piece in front of it
                        if (move_to->piece()->color() == BLACK || ((*it)->name() == PAWN && (*it)->location().second == location.second))
                        {
                            break;
                        }

                        // If piece hits an enemy piece checks for checkmate based on new piece's location and the fact that particular
                        // enemy piece will be captured
                        if (!is_suicide(*it, move_to->piece(), location))
                        {
                            return false;
                        }
                    }
                    else
                    {
                        // If piece is a pawn and attempting to move diagonally without capturing an enemy piece
                        if ((*it)->name() == PAWN && (*it)->location().second != location.second)
                        {
                            break;
                        }

                        // Checks for checkmate based on new piece's location
                        if (!is_suicide(*it, NULL, location))
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }

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