#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fib(int n) {
    if (n < 2) return n;

    int previousToLast = 0, last = 1, aux = 0;

    for (int i = 2; i <= n; i++) {
        aux = previousToLast + last;
        previousToLast = last;
        last = aux;
    }
    return aux;
}

int main(int argc, char **argv) {
    int n, result;
    n = atoi(argv[1]);
    double start = omp_get_wtime();
    result = fib(n);
    double end = omp_get_wtime();
    printf("%.15f\n", end - start);

    return 0;
}
