// Only reason I created this file instead of removing the -fopenmp flag is because I need to use the omp_get_wtime() function for the time
// and if I remove the flag, then it will fail at compile time due to that function

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// The n-result in the fibonacci sequence
int fib(int n) {
    int i, j;
    if (n<2)
        return n;
    i=fib(n-1);
    j=fib(n-2);

    return i+j;
}

int main(int argc, char **argv){
    int n, result;
    char *a = argv[1];
    n = atoi(a);

    double start = omp_get_wtime();
    result = fib(n);
    double end = omp_get_wtime();
    printf("%.15f\n", end - start);

    return 0;
}