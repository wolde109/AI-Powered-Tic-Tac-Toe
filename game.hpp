#ifndef GAME_HPP
#define GAME_HPP

// Checks if a player has won the game for the given board
bool isWinner(const char board[9], char player);

// Checks if the board is full and no one has won
bool isTie(const char board[9]);


#endif
