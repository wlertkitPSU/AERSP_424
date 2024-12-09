#include "game.h"
#include <iostream>

// Constructor
Game::Game()
    : currentPlayerIndex(0), gameOver(false) {
    board = std::make_unique<Board>();
    
    // Initialize players with PlayerColor enum
    players.emplace_back("Player 1", Player::PlayerColor::White); // White pieces
    players.emplace_back("Player 2", Player::PlayerColor::Black); // Black pieces
}

// Starts the game loop
void Game::start() {
    while (!gameOver) {
        displayBoard();
        std::string move = getInputFromUI();
        if (!makeMove(move)) {
            sendMessageToUI("Invalid move. Try again.");
            continue;
        }
        if (isGameOver()) {
            gameOver = true; // Update here instead
            announceWinner();
            break;
        }
        switchPlayer();
    }
}

// Displays the board (this will be updated with graphics later)
void Game::displayBoard() const {
    board->print();
}

// Makes the move by applying it to the board
bool Game::makeMove(const std::string& move) {
    Player::PlayerColor playerColor = players[currentPlayerIndex].getPieceColor();
    return board->applyMove(move, playerColor);
}

// Checks if the game is over (checkmate, stalemate)
bool Game::isGameOver() const {
    Player::PlayerColor currentPlayerColor = players[currentPlayerIndex].getPieceColor();
    char colorChar = (currentPlayerColor == Player::PlayerColor::White) ? 'W' : 'B';
    
    if (board->isCheckmate(colorChar)) {
        sendMessageToUI(players[currentPlayerIndex].getName() + " is in checkmate.");
        return true;
    }
    if (board->isStalemate(colorChar)) {
        sendMessageToUI("The game ends in a stalemate.");
        return true;
    }
    return false;
}

// Announces the winner
void Game::announceWinner() const {
    // Convert PlayerColor to char ('W' or 'B')
    char currentPlayerColor = (players[currentPlayerIndex].getPieceColor() == Player::PlayerColor::White) ? 'W' : 'B';
    
    if (board->isCheckmate(currentPlayerColor)) {
        // The other player is the winner
        int otherPlayerIndex = (currentPlayerIndex + 1) % 2;
        sendMessageToUI(players[otherPlayerIndex].getName() + " wins!");
    } else {
        sendMessageToUI("The game is a draw.");
    }
}

// Switches to the next player
void Game::switchPlayer() {
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

// Gets input from the UI (for now using std::cin)
std::string Game::getInputFromUI() {
    std::string move;
    std::cin >> move; // Placeholder for actual UI input
    return move;
}

// Sends messages to the UI (for now using std::cout)
void Game::sendMessageToUI(const std::string& message) const {
    std::cout << message << std::endl; // Placeholder for actual UI message
}
