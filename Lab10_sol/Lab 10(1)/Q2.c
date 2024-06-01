#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapp(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void swap(int arr[],int a,int b)
{
    swapp(arr+a,arr+b);
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


int main() {
    int arr[] = {0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,1};
    int mid = threePart(arr,0,16,0);
    for (int i = 0; i < 17; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    
    return 0;
}