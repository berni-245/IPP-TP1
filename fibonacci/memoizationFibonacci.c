#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 50
int values[MAX] = {0};
omp_lock_t locks[MAX];

int fib(int n) {
    if (n < 2)
        return n;
    omp_set_lock(&locks[n]); // ensure only one thread is calculating the val of fib(n) at the time

    if (values[n] != 0) { // already calculated
        int val = values[n];
        omp_unset_lock(&locks[n]);
        return val;
    }

    int i = fib(n - 1);
    int j = fib(n - 2);
    int result = i + j;

    values[n] = result;

    omp_unset_lock(&locks[n]);
    return result;
}

int main(int argc, char **argv) {
    int n, result;
    n = atoi(argv[1]);

    for (int k = 0; k < MAX; k++)
        omp_init_lock(&locks[k]);

#pragma omp parallel
    {
#pragma omp single
        result = fib(n);
    }
    printf("Result is %d\n", result);

    for (int k = 0; k < MAX; k++)
        omp_destroy_lock(&locks[k]);
    return 0;
}
