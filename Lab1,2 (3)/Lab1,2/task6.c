#include<stdio.h>
#define MAX 15
int main()
{
    FILE *fptr;
    FILE *fptr2;
    FILE *fptr3;
    fptr = fopen("test1.txt", "r");
    fptr2 = fopen("test2.txt", "w");
    if(fptr == NULL || fptr2 == NULL)
    {
        printf("Error!");
        return 1;
    }
    char s[1000];
    while(fgets(s, 1000, fptr))
    {
        fputs(s,fptr2);
    }
    // fprintf(fptr3, " ");
    printf("HO Gya pencho/n");
    
    fptr3 = fopen("test1.txt", "w");
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr);
}