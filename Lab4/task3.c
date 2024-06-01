#include "intMergeAux.h"
#include "intMerge.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int A[], int st, int en)
{

if (en - st < 1)
return;
int mid = (st + en) / 2;// mid is the floor of (st+en)/2
mergeSort(A, st, mid);// sort the first half
mergeSort(A, mid + 1, en); // sort the second half
merge(A, st, mid, en);

}
int main(int argc, char *argv[])
{
	if(argc < 2){  
      printf("No argument passed through command line.\n");  
   }  
   else{  
      printf("First argument is: %s\n", argv[1]);  
   }
   FILE *fptr;
   fptr = fopen(argv[1],"r");
   if(fptr == NULL)
   {
       printf("Error opening file!");
       // exit(1);
   }
   int arr[1000];
   for (int i = 0; i < 1000; ++i)
   {
        fscanf(fptr,"%d\n",&arr[i]);
   }
   mergeSort(arr,0,1000);
   for (int i = 0; i < 1000; ++i)
   {
   		printf("%d\n",arr[i]);
   }

}