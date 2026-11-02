#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to place queen at position (row, col)
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check left side of the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    
    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    // Check lower diagonal on left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}
// Recursive function to solve N-Queens using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
    // Base case: all queens placed successfully
    if (col >= n) {
        return true;
    }
    
    // Try placing queen in each row of current column
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            // Place queen
            board[i][col] = 1;
            
            // Recursively place remaining queens
            if (solveNQueensUtil(board, col + 1, n)) {
                return true;
            }
            
            // Backtrack: remove queen if solution not found
            board[i][col] = 0;
        }
    }
    return false;
}
// Print the chessboard
void printBoard(vector<vector<int>>& board, int n) {
    cout << "\nN-Queens Solution:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}
int main() {
    int n;
    
    cout << "Enter the value of N (board size): ";
    cin >> n;
    
    if (n < 1 || n > 20) {
        cout << "Please enter N between 1 and 20." << endl;
        return 0;
    }
    
    // Initialize board with all zeros
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    // Place first queen at (0, 0) as per assignment requirement
    board[0][0] = 1;
    
    // Try to solve starting from column 1 (since first queen is placed)
    if (solveNQueensUtil(board, 1, n)) {
        printBoard(board, n);
    } else {
        // If solution not found with first queen at (0,0), try without first queen placement
        cout << "No solution found with first queen at (0,0)." << endl;
        cout << "Trying standard N-Queens solution..." << endl;
        
        // Reset board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = 0;
            }
        }
        
        // Solve standard N-Queens
        if (solveNQueensUtil(board, 0, n)) {
            printBoard(board, n);
        } else {
            cout << "No solution exists for N = " << n << endl;
        }
    }
    
    // Complexity Analysis
    cout << "\nComplexity Analysis:" << endl;
    cout << "Time Complexity: O(N!) in worst case" << endl;
    cout << "Space Complexity: O(N^2) for the board" << endl;
    
    return 0;
}
