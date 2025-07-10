//ai.cpp: Implements AI logic using Minimax to determine optimal moves

#include "game.hpp"
#include "ai.hpp"
#include <algorithm>
#include <limits>

using namespace std;

int getBestMove(char board[9]) {
    int bestScore = numeric_limits<int>::min();
    int bestMove = -1;

    for (int i = 0; i < 9; ++i) {
        if (board[i] != 'X' && board[i] != 'O') {
            char temp = board[i];
            board[i] = 'O';  // AI's move
            int score = minimax(board, false);
            board[i] = temp; // Undo
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    return bestMove;
}

int minimax(char board[9], bool isMaximize) {
    // Base case: check for terminal state
    if (isWinner(board, 'O')) return 10;
    if (isWinner(board, 'X')) return -10;
    if (isTie(board)) return 0;

    
    if (isMaximize) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < 9; ++i) {
            if (board[i] != 'X' && board[i] != 'O') {
                char temp = board[i];
                board[i] = 'O';
                int score = minimax(board, false);
                board[i] = temp;
                bestScore = max(score, bestScore);
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int i = 0; i < 9; ++i) {
            if (board[i] != 'X' && board[i] != 'O') {
                char temp = board[i];
                board[i] = 'X';
                int score = minimax(board, true);
                board[i] = temp;
                bestScore = min(score, bestScore);
            }
        }
        return bestScore;
    }
}

