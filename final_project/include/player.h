#pragma once
#include <string>

class Player {
public:
    // Enum class for PlayerColor (Black or White)
    enum class PlayerColor {
        Black, White
    };

    // Constructor using PlayerColor enum
    Player(std::string name, PlayerColor color);

    // Method to get the piece color as PlayerColor enum
    PlayerColor getPieceColor() const;

    // Method to get the player's name
    std::string getName() const;

private:
    std::string name;
    PlayerColor pieceColor;  // Use PlayerColor enum instead of char
};
