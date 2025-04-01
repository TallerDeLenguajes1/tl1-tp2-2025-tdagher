#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

double vt[N];

int main()
{
    srand(time(NULL));
    double *ptr = vt;

    for (int i = 0; i < N; i++)
    {
        *ptr = 1 + rand() % 100;
        printf("%f\n", *ptr);
    }

    return 0;
}