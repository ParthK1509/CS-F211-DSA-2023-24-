#include <stdio.h>
#include <stdlib.h>



typedef struct person
{
int id;
char *name;
int age;
int height;
int weight;
}PERSON;

void insertionSort(struct person arr[],int n){
    int i,j;
    struct person key;
    for(i=1;i<n;i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j].height>key.height){
            arr[j+1]=arr[j];
            j--;
        
        }
        arr[j+1]=key;
    }
}

void printTable(PERSON A[],int n)
{
for(int j = 0;j<n;j++)
{
    printf("%d ",A[j].id);
    printf("%s ",A[j].name);
    printf("%d ",A[j].age);
    printf("%d ",A[j].height);
    printf("%d ",A[j].weight);
    printf("\n");
}
}
int main()
{
    PERSON *table = (PERSON *)malloc(sizeof(PERSON)*5);
    table[0].id=1;
    table[0].name="Sokka";
    table[0].age=15;
    table[0].height=150;
    table[0].weight=45;

    table[1].id=2;
    table[1].name="Aang";
    table[1].age=112;
    table[1].height=137;
    table[1].weight=35;

    table[2].id=3;
    table[2].name="zuko";
    table[2].age=16;
    table[2].height=160;
    table[2].weight=50;

    table[3].id=4;
    table[3].name="Katara";
    table[3].age=14;
    table[3].height=145;
    table[3].weight=38;

    table[4].id=5;
    table[4].name="Toph";
    table[4].age=12;
    table[4].height=112;
    table[4].weight=30;

    


    




    printTable(table,5);
    insertionSort(table,5);
    printf("\n");
    printTable(table,5);


}


