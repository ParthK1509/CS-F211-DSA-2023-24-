#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct person {
    int id;
    char *name; 
    int age; 
    int height; 
    int weight;
}PERSON;

void swapp(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void swap(int arr[],int a,int b)
{
    swapp(arr+a,arr+b);
}

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

int threePart(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, hi - 1);
    int pivPos, lt, rt, mid, pv;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    pv = Ls[hi - 1];
    while (mid <= rt)
    {
        if (Ls[mid] < pv)
        {
            swap(Ls, lt, mid);
            lt++;
            mid++;
        }
        else if (Ls[mid] > pv)
        {
            swap(Ls, mid, rt);
            rt--;
        }   
        else
        {
            mid++;
        }
    }

    swap(Ls, mid, hi - 1);

    return mid;
}

int lumotu(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(arr,i,j); 
        } 
    } 
    swap(arr, i+1,high); 
    return (i + 1); 
} 

// Ls[lo..hi] is the input array; Ls[pInd] is the pivot
int part(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt)
    {
        for (; lt <= hi && Ls[lt] <= pv; lt++);
        // Ls[j]<=pv for j in lo..lt-1
        for (; Ls[rt] > pv; rt--);
        // Ls[j]>pv for j in rt+1..hi
        if (lt < rt)
        {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt] < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    
    swap(Ls, lo, pivPos);
    // Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and (Ls[j]>pv for j in
    //pivPos+1..hi)
    return pivPos;
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
    PERSON * table2 = createTable("dat100000.csv",100000);
    PERSON * table3 = createTable("dat100000.csv",100000);
    int h1[100000];
    int h2[100000];
    int h3[100000];
    for (int i = 0; i < 100000; ++i)
    {
        h1[i] = table1[i].height;
        h2[i] = table2[i].height;
        h3[i] = table3[i].height;
    }

    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    int mid = part(h1,0,100000,500);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The part took %f seconds to execute\n", time_taken);


    gettimeofday(&t1, NULL);
    mid = lumotu(h2,0,100000);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The lumotu took %f seconds to execute\n", time_taken);

    gettimeofday(&t1, NULL);
    mid = threePart(h3,0,100000,500);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The threepart took %f seconds to execute\n", time_taken);

	// insertionSort(table1,1000);
	// printf("\n\n\n\n");
	// printTable(table1,1000);
    // Free memory allocated for tables
    for (int i = 0; i < 100000; ++i) {
        free(table1[i].name);
        // Add other dynamically allocated fields if any
    }
    free(table1);
    free(table2);
    free(table3);

    return 0;
    return 0;
}