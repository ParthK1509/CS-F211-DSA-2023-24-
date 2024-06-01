#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intMergeAux.h"
#include "intMerge.h"

typedef struct person {
    int id;
    char *name; 
    int age; 
    int height; 
    int weight;
}PERSON;

void mergeSort(int A[], int st, int en)
{

if (en - st < 1)
return;
int mid = (st + en) / 2;// mid is the floor of (st+en)/2
mergeSort(A, st, mid);// sort the first half
mergeSort(A, mid + 1, en); // sort the second half
merge(A, st, mid, en);

}

void printTable(PERSON table[], int n)
{
    for(int j=0;j<n;j++)
    {
        printf("%d ",table[j].id);
        printf("%s ",table[j].name);
        printf("%d ",table[j].age);
        printf("%d ",table[j].weight);
        printf("%d ",table[j].height);
        printf("\n");
    }
}



PERSON * makeTable(char * fileName,int size)
{
    FILE *fptr;
    fptr = fopen(fileName,"r");
    if(fptr == NULL)
    {
        printf("Error opening file!");
        // exit(1);
    }
    PERSON * table = (PERSON *) malloc(sizeof(PERSON)*size);
    for (int i = 0; i < size; ++i)
    {
        int a,b,c,d;
        char* e,dum;
        e = (char*)malloc(100);
        fscanf(fptr,"%d,%[^,],%d,%d,%d\n",&a,e,&b,&c,&d);
        // fscanf(fptr,"%s\n",e);
        // printf("%d");
        table[i].id = a;
        table[i].name = (char*)e;
        table[i].age = b;
        table[i].height = c;
        table[i].weight = d;
    }
    return table;
}
void main(int argc, char *argv[] )  {  
  
   // printf("Program name is: %s\n", argv[0]);  
   
   if(argc < 2){  
      printf("No argument passed through command line.\n");  
   }  
   else{  
      printf("First argument is: %s\n", argv[1]);  
   }
   int n = 1000;
   PERSON* table = makeTable(argv[1],n);
   int height[n];
   for (int i = 0; i < n; ++i)
   {
        height[i] = table[i].height;
   }
   mergeSort(height,0,n);
   for (int i = 0; i < n; ++i)
   {
        table[i].height = height[i];
   }
   printTable(table,n);

}  