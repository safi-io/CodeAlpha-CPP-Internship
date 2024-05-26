#include <iostream>
using namespace std;

class Sudoku {
private:
    int board[9][9]; // 2D array to represent the Sudoku board
    const int SIZE = 9; // Size of the board
    const int SUBGRID_SIZE = 3; // Size of the subgrid

public:
    // Constructor to initialize the board
    Sudoku() {
        initializeBoard();
    }

    // Function to initialize the board with predefined values
    void initializeBoard() {
        int initialBoard[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                board[i][j] = initialBoard[i][j];
    }

    // Function to print the Sudoku board
    void printBoard() {
        for (int i = 0; i < SIZE; ++i) {
            if (i % SUBGRID_SIZE == 0 && i != 0) {
                cout << "---------------------" << endl;
            }
            for (int j = 0; j < SIZE; ++j) {
                if (j % SUBGRID_SIZE == 0 && j != 0) {
                    cout << "| ";
                }
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to check if placing a number at a specific position is valid
    bool isValidMove(int row, int col, int num) {
        for (int i = 0; i < SIZE; ++i) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }

        int startRow = row - row % SUBGRID_SIZE;
        int startCol = col - col % SUBGRID_SIZE;
        for (int i = 0; i < SUBGRID_SIZE; ++i) {
            for (int j = 0; j < SUBGRID_SIZE; ++j) {
                if (board[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    // Function to check if the board is complete
    bool isComplete() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // Function to play the game
    void play() {
        while (!isComplete()) {
            printBoard();
            int row, col, num;
            cout << "Enter row, column, and number (1-9) to place (e.g., 1 2 3): ";
            cin >> row >> col >> num;

            // Check if input values are within valid range
            if (row < 1 || row > SIZE || col < 1 || col > SIZE || num < 1 || num > 9) {
                cout << "Invalid input. Try again." << endl;
                continue;
            }

            row--; col--; // Adjust for 0-indexed board

            // Check if the cell is already filled
            if (board[row][col] != 0) {
                cout << "Cell already filled. Try again." << endl;
                continue;
            }

            // Validate and place the number
            if (isValidMove(row, col, num)) {
                board[row][col] = num;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        // Congratulate the player upon completion
        cout << "Congratulations! You completed the Sudoku puzzle." << endl;
        printBoard();
    }
};

int main() {
    Sudoku game;
    game.play();
    return 0;
}
