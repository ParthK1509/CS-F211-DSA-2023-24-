#include "intMergeAux.h"
#include "intMerge.h"
#include <stdio.h>
#include <stdlib.h>

void mergeAux(int A[], int s1, int e1, int B[], int s2, int e2, int C[], int s3, int e3)
{
	if(s1 == e1+1)
	{
		int x=0;
		while(s2!=e2+1)
		{
			C[s3+(x++)] = B[s2++]; 
		}
		return;
	}
	if(s2 == e2+1)
	{
		int x=0;
		while(s1!=e1+1)
		{
			C[s3+(x++)] = B[s1++]; 
		}
		return;
	}
	if(s3 == e3+1)
	{
		printf("INVALID_SIZE\n");
	}

	if (A[s1] > B[s2])
	{
		C[s3] = B[s2];
		mergeAux(A, s1, e1, B, s2 + 1, e2, C, s3 + 1, e3);
	}
	else
	{
		C[s3] = A[s1];
		mergeAux(A, s1 + 1, e1, B, s2, e2, C, s3 + 1, e3);
	}
}