#include "player.h"

// Constructor
Player::Player(std::string name, PlayerColor color)
    : name(std::move(name)), pieceColor(color) {}

// Get the player's color
Player::PlayerColor Player::getPieceColor() const {
    return pieceColor;
}

// Get the player's name
std::string Player::getName() const {
    return name;
}
