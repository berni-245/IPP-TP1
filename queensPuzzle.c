#include <stdio.h>
#include <stdbool.h>

#define N 4

long long solutions = 0;

bool is_safe(int *board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
          board[i] - i == col - row ||
          board[i] + i == col + row)
            return false;
    }
    return true;
}

void solve(int row, int *board) {
    if (row == N) {
        solutions++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (is_safe(board, row, col)) {
            board[row] = col;
            solve(row + 1, board);
        }
    }
}



int main() {
    int board[N];
    solve(0, board);
    printf("Soluciones para %d reinas: %lld\n", N, solutions);
    return 0;
}