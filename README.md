# Memory Game Documentation
## Overview
This memory game is a two-player interactive game built in C++ where players take turns flipping cards on a grid to find matching pairs. The game incorporates bonus and penalty card mechanics, adding strategic depth. The player's objective is to score the highest points by matching pairs and managing bonus/penalty cards effectively.

## Features
### Card Types:

StandardCard: A basic card with a number and points.
BonusCard: Grants additional points or a chance for another turn.
PenaltyCard: Deducts points or skips the next turn.
Deck:

A 4x4 grid containing shuffled cards (pairs of each type).
Supports displaying the grid with hidden and revealed card states.
Players:

Two players compete by flipping cards and gaining points.
Each player has a score tracked throughout the game.
Game Mechanics:

Players flip two cards per turn, attempting to match pairs.
Bonus and penalty mechanics are triggered based on card types.
The game ends when all cards are flipped, declaring the winner based on scores.
Interactive Gameplay:

Players input grid coordinates to flip cards.
Immediate feedback is provided based on the type of cards flipped.
Code Structure
Classes:

Card: Represents a generic card with basic attributes (number, points, flipped state).
BonusCard and PenaltyCard: Specialized cards extending the Card class with additional behavior.
Deck: Manages the 4x4 grid of cards, shuffling, and displaying the grid.
Player: Represents a player with a name and score.
Game: Orchestrates the game flow, including initialization, turns, and game conclusion.
Functions:

Game::initializeGame: Prepares the game by setting up players and the deck.
Game::PlayerTurn: Handles a single player's turn.
Game::handleCards: Manages card interactions and scoring logic.
Game::EndGame: Determines and announces the winner.
Deck::shuffle: Randomizes the card grid.
Deck::displayGrid: Displays the current state of the card grid.
Main Function:

Initializes the game and starts the gameplay loop.
Key Highlights
Modular Design: Each class and function handles specific responsibilities, making the code organized and maintainable.
Randomization: Cards are shuffled using a modern random device for fairness.
Interactive Flow: Players are prompted for input during their turn, making the game engaging.
Strategic Depth: Bonus and penalty cards add layers of strategy to simple pair-matching gameplay.
Improvements and Future Enhancements
Error Handling: Add checks for invalid inputs (e.g., coordinates out of bounds).
AI Player: Include a single-player mode with a computer opponent.
Graphical Interface: Enhance user experience with a GUI instead of a console-based display.
Scalability: Allow configurable grid sizes and more diverse card types.
Usage Instructions
Compile the code using a C++ compiler.
Run the executable and follow the prompts to enter player names.
Players alternate turns, entering the grid coordinates of cards to flip.
Continue until all cards are flipped. The player with the highest score wins!
