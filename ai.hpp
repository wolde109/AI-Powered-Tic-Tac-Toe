#ifndef AI_HPP
#define AI_HPP

// Determines the best possible move for the AI (O)
int getBestMove(char board[9]);

int minimax(char board[9], bool isMaximize);

#endif
