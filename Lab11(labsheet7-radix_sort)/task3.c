#include <stdio.h>

// Function to take input an array A and return an array B after performing counting sort on it with array C
int* counting_sort(int* A, int* B, int n,int place) 
{
    //changing array A in A2 1390 -> 3 = 13 - 10
    int A2[n];
    for (int i = 0; i < n; ++i)
    {
        A2[i] = A[i]/place - ((int)A[i]/(10*place))*10;
        // printf("%d",A2[i]);
    }

    int k = 10;
        // printf("-kfinal->%d",k);


    // Initialize array C with all 0s
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }

    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        C[A2[j]]++;
    }
    
    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n-1; j >= 0; j--) 
    {
        B[C[A2[j]] - 1] = A[j];
        C[A2[j]]--;
    }
    return B;
}

// Driver code to test the above function
int main() 
{
    int n = 10;
    // printf("Enter the number of elements in the array: ");
    // scanf("%d", &n);
    int A[] = {2,200,39,143,548,2349,2323,66,345,10};
    // printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) 
    {
        // scanf("%d", &A[i]);
    }
    int k = A[0];
    for (int i = 1; i < n; i++) 
    {
        if (A[i] > k) 
        {
            k = A[i];
        }
    }
    int B[n];
    int* sorted_array = counting_sort(A, B, n,100);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", B[i]);
    }
    printf("\n");
    return 0;
}