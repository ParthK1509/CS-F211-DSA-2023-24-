#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    int id;
    char *name; 
    int age; 
    int height; 
    int weight;
}PERSON;

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

void insertionSort(PERSON arr[], int n){
    int i, j;
    struct person key;

    for (i=1;i<n;i++) {
        key = arr[i];
        j = i - 1;
        while (j>=0 && arr[j].height>key.height)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
   insertionSort(table,n);
   printTable(table,n);

}  