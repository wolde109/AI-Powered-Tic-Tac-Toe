# Tic Tac Toe (C++)

A simple terminal-based Tic Tac Toe game where you (Player X) play against an AI (Player O) that uses the **Minimax algorithm** to make optimal moves.

## 🎮 Features

- 3x3 Tic Tac Toe game board
- Human player vs AI
- AI is unbeatable (uses Minimax)
- Fully playable in the terminal

## 🧠 AI Logic

The AI uses the **Minimax algorithm**, a recursive decision-making algorithm commonly used in game theory. It simulates every possible future move to choose the best one:

- **+10** for AI win  
- **-10** for Human win  
- **0** for a tie

At each turn, the AI maximizes its score while assuming the human player plays optimally to minimize the AI's score.

## 🗂️ File Structure
main.cpp // Game loop and user interface

ai.cpp // AI logic (getBestMove, minimax)

ai.hpp // AI function declarations

game.hpp // Declarations for isWinner and isTie


## 🚀 How to Compile & Run

Make sure you have a C++ compiler (like `g++`).


### Compile:
```bash
g++ main.cpp ai.cpp -o tictactoe

### Run:
```bash
./tictactoe


Sample Gameplay:
```bash
Tic Tac Toe: You (X) vs AI (O)
 1 | 2 | 3 
 4 | 5 | 6 
 7 | 8 | 9 
Enter your move (1-9): 5
AI chooses 1
 O | 2 | 3 
 4 | X | 6 
 7 | 8 | 9 
...




