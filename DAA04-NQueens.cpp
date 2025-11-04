#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    // Check left side of this row
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    // Upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solve(vector<vector<int>> &board, int col, int N) {
    if (col == N) return true;

    // Skip the column that already has the user’s queen
    for (int i = 0; i < N; i++) {
        if (board[i][col]) continue;

        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solve(board, col + 1, N))
                return true;
            board[i][col] = 0;  // backtrack
        }
    }
    return false;
}

void printBoard(vector<vector<int>> &board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter board size (N): ";
    cin >> N;

    int r, c;
    cout << "Enter row (1-" << N << "): ";
    cin >> r;
    cout << "Enter column (1-" << N << "): ";
    cin >> c;
    r--; c--; // convert to 0-indexed

    vector<vector<int>> board(N, vector<int>(N, 0));
    board[r][c] = 1; // user places first queen

    // Try to solve from column 0 onward
    if (solve(board, 0, N))
        printBoard(board, N);
    else
        cout << "No solution exists.\n";

    return 0;
}
