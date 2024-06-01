#include <stdio.h>
#include <string.h>
// Function to take input an array A and return an array B after performing counting sort on it with array C
int* counting_sort(int* A, int* B, int k, int n) 
{
    // Initialize array C with all 0s
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }

    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        C[A[j]]++;
    }
    
    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
    return B;
}

// Driver code to test the above function
int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    char A[n];
    printf("Enter the elements of the string: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", A);
    }
    int k = (int)A[0];
    // printf("%c",(char)k);
    for (int i = 1; i < strlen(A); i++) 
    {
        if ((int)A[i] > k) 
        {
            k = A[i];
        }
    }


    int B[strlen(A)],A2[strlen(A)];
    for (int i = 0; i < strlen(A); ++i)
    {
        A2[i] = (int)A[i];
        
    }
    int* sorted_array = counting_sort(A2, B, k + 1, strlen(A));
    printf("The sorted array is: ");
    for (int i = 0; i < strlen(A); i++) 
    {
        printf("%c", (char)sorted_array[i]);
    }
    printf("\n");
    return 0;
}