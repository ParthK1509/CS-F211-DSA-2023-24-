#include<stdio.h>
int main()
{
    char * s = "Hello, World!";
    for (int n = 0; n < 3; n++)
    {

    printf("%p p\n",s);
    printf("%x x\n",s);
    printf("%p\n",&s[1]);
    }
    
    return 0;
}