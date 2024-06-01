#include<stdio.h>

void counting_sort(int* A, int* B, int n,int place) 
{
    //changing array A in A2 1390 -> 3 = 13 - 10
    int A2[n];
    for (int i = 0; i < n; ++i)
    {
        A2[i] = A[i]/place - ((int)A[i]/(10*place))*10;
        // printf("%d",A2[i]);
    }

    int k = 10;
    
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
    for (int j = n - 1; j >= 0; j--) 
    {
        B[C[A2[j]] - 1] = A[j];
        C[A2[j]]--;
    }
}

int* radix_sort(int * A, int *B,int n,int noofdigits)
{
	counting_sort(A,B,n,1);
	int C[n];
	for (int i = 0; i < n; ++i)
	{
		C[i] = 0;
	}
	int place=1;
	//my ans is in B, initial array in A, so i need to swap;
	for (int i = 1; i < noofdigits; ++i)
	{
		place*=10;
		for (int i = 0; i < n; ++i)
		{
			A[i] = B[i];
		}
		counting_sort(A,B,n,place);
	}
	return B;
}


int* decToBinary(int n)
{
    int binaryNum[32];
 	for (int i = 0; i < 32; ++i)
 	{
 		binaryNum[i] = 0;
 	}
    
    int i = 0;
    while (n > 0) {
    
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 	
 	return binaryNum;
}

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void radix_ex_helper(int* A,int* B,int n,int l,int r,int currdigit)
{
	if(currdigit < 0)
	{
		return;
	}
	int arr[r-l+1];
	int binaryarr[r-l+1][32];
	for (int i = 0; i < r-l+1; ++i)
	{
		binaryarr[i] = dectoBinary(A[l+i]);
	}
	int stptr=l,endptr=r;
	while(stptr<endptr)
	{
		for (; stptr <= r && binaryarr[stptr][currdigit] == 0; stptr++);
		for (; endptr >= l && Ls[endptr] == 1; endptr--);

		swap(binaryarr[stptr],binaryarr[endptr]);
		swap(A[stptr],A[endptr]);
		stptr++;
		endptr--;
	}
	radix_ex_helper(A,B,n,l,stptr,currdigit-1);
	radix_ex_helper(A,B,n,stptr,r,currdigit-1);

}

int* radix_exchange_sort(int* A,int* B,int n,int noofdigits)
{
	int binaryarray[n][32];
	for (int i = 0; i < n; ++i)
	{
		binaryarray[i] = decToBinary(A[i]);
	}
	/*
	now i have to take the last digit of this binary array sort the array according to it,
	sorting: take the full array and swap the full pointer of the array whereever i need to swap
	then make different partition (l and r), and then call again
	
	*/

}



int main() 
{
    int A[] = {2,200,39,143,548,2349,2323,66,345,10};
    

    FILE * fp;
    fp = fopen("n_integers.txt","r");
    for (int i = 0; i < 1000; ++i)
    {
    	int n;
    	fscanf(fp,"%d,[",&n);
    	int arr[n];
    	for (int i = 0; i < n; ++i)
    	{
    		fscanf(fp,"%d",&arr[i]);
    	}
    	int B[n];
    	fscanf(fp,"]\n");
    	int* sorted_array = radix_sort(arr, B, n, 4);

    	printf("The sorted array is: ");
	    for (int i = 0; i < n; i++) 
	    {
	        printf("%d ", B[i]);
	    }
	    printf("\n");
    	
    }
    fclose(fp);

    // int* sorted_array = radix_sort(A, B, n, 4);
    // printf("The sorted array is: ");
    // for (int i = 0; i < n; i++) 
    // {
    //     printf("%d ", B[i]);
    // }
    // printf("\n");
    return 0;
}


