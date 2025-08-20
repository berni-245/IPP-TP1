#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int fib(int n, int nThreshold) {
    int i, j;
    if (n<2)
        return n;
    if (n < nThreshold)
        return fib(n-1, nThreshold) + fib(n-2, nThreshold);
#pragma omp task shared(i)
        i=fib(n-1, nThreshold);
#pragma omp task shared(j)
        j=fib(n-2, nThreshold);
#pragma omp taskwait
        return i+j;
}

int main(int argc, char **argv){
    int n, nThreadhold, result;
    char *a = argv[1];
    n = atoi(a);
    nThreadhold = MAX(20, (int) (n*0.75));
    printf("%d\n", nThreadhold);

#pragma omp parallel
    {
#pragma omp single
        result = fib(n, nThreadhold);
    }
    printf("Result is %d\n", result);
}