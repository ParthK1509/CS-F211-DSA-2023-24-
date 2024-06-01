#include<stdio.h>
#define MAX 15
int main()
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen(__FILE__, "r");
    if(fptr == NULL)
    {
        printf("Error!");
        return 1;
    }
    char s[1000];
    char buf[MAX];
 
    // using fgets to take input from stdin
    fgets(buf, MAX, stdin);
    printf("string is: %s\n", buf);

    while(fgets(s, 1000, fptr))
    {
        printf("%s\n",s);
    }
    printf("string is: %s\n", buf);

}