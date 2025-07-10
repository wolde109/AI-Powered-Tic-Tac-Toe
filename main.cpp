// main.cpp: Runs the Tic Tac Toe game. Human (X) vs AI (O) using Minimax algorithm.



#include <iostream>
#include "ai.hpp"
#include "game.hpp"

using namespace std;

char board[9] = { '1','2','3','4','5','6','7','8','9' }; // Represents the 3x3 Tic Tac Toe board using a 1D array

void printBoard() {
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0) { //creates new row at 3, 6, and 9 (starts at 1 hence i + 1)
            cout << "\n";
        }
        else cout << "|"; //if not 3, 6, 9, split the two numbers by a vertical line
    }
    cout << "\n";
}

bool isWinner(const char board[9], char player) {
    // horizontal, vertical, diagonal win conditions
    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    for (int i = 0; i < 8; i++) {
        int* combo = wins[i]; //combo is pointer to a specific winning combo
        if (board[combo[0]] == player && board[combo[1]] == player && board[combo[2]] == player) { //check to see if its a winning combo
            return true;
        }
    }
     return false;
}

bool isTie(const char board[9]) {
    for (int i = 0; i < 9; ++i)
        if (board[i] != 'X' && board[i] != 'O') //check to see if spaces on board are filled
            return false; //if not, continue playing
    return true; //stops when full
}

//Main game loop handling user and AI moves
int main() {
    cout << "Tic Tac Toe: You (X) vs AI (O)\n";

    while (true) {
        printBoard();

        // Player move
        int move;
        cout << "Enter your move (1-9): ";
        cin >> move;
        move--; // Convert to 0-based index

        if (move < 0 || move > 8 || board[move] == 'X' || board[move] == 'O') { //checks for valid moves on board
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move] = 'X';
        if (isWinner(board, 'X')) {
            printBoard();
            cout << "You win!\n";
            break;
        }
        if (isTie(board)) {
            printBoard();
            cout << "It's a tie!\n";
            break;
        }

        // AI move
        int aiMove = getBestMove(board);  
        board[aiMove] = 'O';
        cout << "AI chooses " << (aiMove + 1) << "\n";

        if (isWinner(board, 'O')) {
            printBoard();
            cout << "AI wins!\n";
            break;
        }
        if (isTie(board)) {
            printBoard();
            cout << "It's a tie!\n";
            break;
        }
    }

    return 0;
}
