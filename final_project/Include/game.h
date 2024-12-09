#pragma once
#include <memory>
#include <vector>
#include "board.h"
#include "player.h"

class Game {
public:
    Game();
    void start();
    void displayBoard() const;
    bool makeMove(const std::string& move);
    bool isGameOver() const;
    void announceWinner() const;

private:
    std::unique_ptr<Board> board;
    std::vector<Player> players;
    int currentPlayerIndex;
    bool gameOver;

    void switchPlayer();
    std::string getInputFromUI();
    void sendMessageToUI(const std::string& message) const;
};
