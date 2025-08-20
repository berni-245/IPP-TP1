#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fib(int n) {
    if (n < 2) return n;

    int previousToLast = 0, last = 1, aux = 0;

#pragma omp parallel
    {
#pragma omp for ordered
        for (int i = 2; i <= n; i++) {
#pragma omp ordered
            {
                aux = previousToLast + last;
                previousToLast = last;
                last = aux;
            }
        }
    }

    return aux;
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int result = fib(n);
    printf("Result is %d\n", result);
    return 0;
}
