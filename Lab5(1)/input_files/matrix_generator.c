#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main(void)
{
    // Asks user for n as input and creates a square matrix of size nxn populating it with random integers
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
    int matrix2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix2[i][j] = rand() % 100;
        }
    }
    struct timeval start, end;
    int temp1;
    
    int matrix3[n][n];
    gettimeofday(&start, NULL);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix3[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }
    gettimeofday(&end, NULL);

    printf("Time taken for sequential add on matrix: %ld microseconds\n",
        ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
    

    int matrix4[n][n];
    gettimeofday(&start, NULL);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix4[j][i] = matrix[j][i] + matrix2[j][i];
        }
    }
    gettimeofday(&end, NULL);
    printf("Time taken for non sequential add on matrix: %ld microseconds\n",
        ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 +
        start.tv_usec)));
}