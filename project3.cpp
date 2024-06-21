#include <iostream>
#include <vector>
using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the board is full (tie condition)
bool checkTie(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // There's an empty cell, game is not tied
        }
    }
    return true; // All cells are filled, game is tied
}


// Main function
int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    //playGame function;
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize board with empty spaces
    char currentPlayer = 'X'; // X starts the game

    while (true) {
        drawBoard(board);

        // Input move from player
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row [1-3] column [1-3]): ";
        cin >> row >> col;

        // Convert to zero-indexed
        row--;
        col--;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check if current player wins
            if (checkWin(board, currentPlayer)) {
                drawBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check if the game is tied
            if (checkTie(board)) {
                drawBoard(board);
                cout << "It's a tie!" << endl;
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }
    return 0;
}
