#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <omp.h>
#define FIRST_COL 0

long long solutions = 0;
int N;

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
#pragma omp atomic
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

void n_queens() {
#pragma omp parallel for reduction(+:solutions)
    for (int col = FIRST_COL; col < N; col++) {
        int board[N];
        board[FIRST_COL] = col;
        solve(FIRST_COL + 1, board);
    }
}



int main(int argc, char **argv) {
    char *a = argv[1];
    N = atoi(a);
    double start = omp_get_wtime();
    n_queens();
    double end = omp_get_wtime();
    // printf("Soluciones para %d reinas: %lld\n", N, solutions);
    printf("%.15f\n", end - start);
    return 0;
}