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

PERSON * createTable(char * file_name,int size)
{
	FILE *fp;
	PERSON * table = (PERSON *) malloc(sizeof(PERSON)*size);
	fp = fopen(file_name,"r");
	if(fp==NULL)
		printf("error");
	for(int j =0; j<size;j++)
	{
		table[j].name = (char *) (malloc(sizeof(char)*100));
		fscanf(fp,"%d,%[^,],%d,%d,%d\n",&(table[j].id),table[j].name,&(table[j].age),&(table[j].weight),&(table[j].height));
		
	}

	return table;
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

void insertionSort(PERSON arr[], int n){
    int i, j;
    struct person key;

    for (i=1;i<n;i++) {
        key = arr[i];
        j = i - 1;
        while (j>=0 && arr[j].height>key.height) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
} 

int main() {
    PERSON * table1 = createTable("dat100000.csv",100000);
	insertionSort(table1,100000);
	printf("\n\n\n\n");
	printTable(table1,100000);
    return 0;
}