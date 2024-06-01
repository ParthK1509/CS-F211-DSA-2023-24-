#include "intMergeAux.h"
#include "intMerge.h"
#include <stdio.h>
#include <stdlib.h>

void mergeAux(int A[], int s1, int e1, int B[], int s2, int e2, int C[], int s3, int e3)
{
	int i=s1,j=s2,k=s3;
	i=s1; j=s2; k=s3;
	while (i <= e1 && j <= e2) 
	{
	if (L1[i] < L2[j])
		L3[k++] = L1[i++];
	else
		L3[k++] = L2[j++];
	}

	while (i <= e1)
	{		
		L3[k++] = L1[i++];
	}
	while (j <= e2)
	{
		L3[k++] = L2[j++];
	}
}