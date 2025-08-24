#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
#include <string.h>

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
            int *new_board = malloc(N * sizeof(int));
            memcpy(new_board, board, row * sizeof(int));
            new_board[row] = col;

#pragma omp task firstprivate(row, new_board)
            {
                solve(row + 1, new_board);
                free(new_board);
            }
        }
    }
}

int main(int argc, char **argv) {
    char *a = argv[1];
    N = atoi(a);
    int board[N];
    double start = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp single
        {
            solve(0, board);
        }
    }

    double end = omp_get_wtime();
    // printf("Soluciones para %d reinas: %lld\n", N, solutions);
    printf("%.15f\n", end - start);
    return 0;
}