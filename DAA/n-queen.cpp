#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<bool>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<bool>> &board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }
    // Left Diagonal
    int shiftLeft = min(row, col);
    for (int i = 1; i <= shiftLeft; i++) {
        if (board[row - i][col - i]) {
            return false;
        }
    }
    // Right Diagonal
    int shiftRight = min(row, n - col - 1);
    for (int i = 1; i <= shiftRight; i++) {
        if (board[row - i][col + i]) {
            return false;
        }
    }
    return true;
}

int queensB(vector<vector<bool>> &board, int row) {
    if (row == board.size()) {
        display(board);
        return 1;
    }
    int count = 0;
    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = true;
            count += queensB(board, row + 1);
            board[row][col] = false;
        }
    }
    return count;
}

void backtracking(int n) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    int totalArrangements = queensB(board, 0);
    cout << "Total possible arrangements: " << totalArrangements << endl;
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    cout << "Backtracking" << endl;
    backtracking(n);

    return 0;
}
