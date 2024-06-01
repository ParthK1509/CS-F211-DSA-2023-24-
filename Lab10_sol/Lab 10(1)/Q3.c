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

int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}

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

int selectt(int L[], int n, int k)
{
	if (k == 0)
		return L[0];
	if (n <= 5){
		for (int i = 1; i < n; i++)
			for (int j = i-1; j >= 0; j--)
				if (L[j] > L[j+1])
					swap(L, j, j+1);
				else
					break;
		return L[k-1];
	}

	// partition L into subsets of five elements each
	//(there will be n/5 subsets total).
	
	int numGroups;
	if (n % 5 == 0)
		numGroups = n/5;
	else
		numGroups = n/5 + 1;
	int medians[numGroups];
	
	for (int i = 0; i < numGroups; i++)
	{
		medians[i] = selectt(L + i*5, min(5, n - i*5), min(5, n - i*5)/2);
	}
	int M = selectt(medians, numGroups, (numGroups+1)/2);
	// Partition array into two halves, L1, {M} and L2, such that
	// L1 contains elements <= M, {M} contains one instance of M and L2 contains all elements > M
	int mInd;
	for (int i = 0; i < n; i++)
	{
		if (L[i] == M)
		{
		mInd = i;
		break;
		}
	}
	int pInd = part(L, 0, n-1, mInd);
	if (k <= pInd)
		return selectt(L, pInd, k);
	else if (k > pInd + 1)
		return selectt(L + pInd + 1, n - pInd - 1, k - pInd - 1);
	else
		return L[pInd];
}

int qselectt(int L[], int n, int k)
{
	int pivot = 0;
	int lo = 0;
	int hi = n - 1;
	int pInd = part(L, lo, hi, pivot);
	if (k <= pInd)
		return qselectt(L, pInd, k);
	else if (k > pInd + 1)
		return qselectt(L + pInd + 1, n - pInd - 1, k - pInd - 1);
	else
		return L[pInd];
}

int randomPivot(int lo, int hi)
{
struct timeval tv;
gettimeofday(&tv, NULL);
srand(tv.tv_usec * 1000000 + tv.tv_sec);

return (rand() % (hi - lo)) + lo;
}


void qs1(int Ls[], int lo, int hi)
{
	if (lo < hi)
	{
		int p = selectt(Ls, lo, hi);
		// Ls[p] is the pivot
		p = part(Ls, lo, hi, p); // Ls[p] is the pivot
		/*
		(Ls[j]<=Ls[p] for j in lo..pPos-1) and
		(Ls[j]>Ls[p] for j in pPos+1..hi)
		*/
		qs1(Ls, lo, p - 1);
		qs1(Ls, p + 1, hi);
	}
}
void qs2(int Ls[], int lo, int hi)
{
	if (lo < hi)
	{
		int p = qselectt(Ls, lo, hi);
		// Ls[p] is the pivot
		p = part(Ls, lo, hi, p); // Ls[p] is the pivot
		/*
		(Ls[j]<=Ls[p] for j in lo..pPos-1) and
		(Ls[j]>Ls[p] for j in pPos+1..hi)
		*/
		qs2(Ls, lo, p - 1);
		qs2(Ls, p + 1, hi);
	}
}
void qs3(int Ls[], int lo, int hi)
{
	if (lo < hi)
	{
		int p = randomPivot(lo, hi);
		// Ls[p] is the pivot
		p = part(Ls, lo, hi, p); // Ls[p] is the pivot
		/*
		(Ls[j]<=Ls[p] for j in lo..pPos-1) and
		(Ls[j]>Ls[p] for j in pPos+1..hi)
		*/
		qs3(Ls, lo, p - 1);
		qs3(Ls, p + 1, hi);
	}
}
int main() {
    PERSON * table1 = createTable("dat10000.csv",10000);
    PERSON * table2 = createTable("dat10000.csv",10000);
    PERSON * table3 = createTable("dat10000.csv",10000);
    int h1[10000];
    int h2[10000];
    int h3[10000];
    for (int i = 0; i < 10000; ++i)
    {
        h1[i] = table1[i].height;
        h2[i] = table2[i].height;
        h3[i] = table3[i].height;
    }

    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    // int mid = part(h1,0,10000,500);
    qs1(h1,0,10000);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The selectt took %f seconds to execute\n", time_taken);


    gettimeofday(&t1, NULL);
    // mid = lumotu(h2,0,10000);
    qs2(h1,0,10000);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The qselectt took %f seconds to execute\n", time_taken);

    gettimeofday(&t1, NULL);
    // mid = threePart(h3,0,10000,500);
    qs3(h1,0,10000);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The randomPivot took %f seconds to execute\n", time_taken);

	// insertionSort(table1,10000);
	// printf("\n\n\n\n");
	// printTable(table1,1000);
    return 0;
}