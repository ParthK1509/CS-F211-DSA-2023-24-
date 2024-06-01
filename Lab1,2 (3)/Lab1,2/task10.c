#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/time.h>

typedef struct student * Student;
struct student
{
    char ID[20];
    char cgpa[20];
};

int main()
{
    FILE * fptr;
    fptr = fopen("data.txt", "r");

    //dynamic array
    Student s;
    s = (Student)calloc(10, sizeof(struct student));
    for (int i = 0; i < 10; i++)
    {
        fscanf(fptr,"%[^ ] %s\n",s[i].ID,s[i].cgpa);
        if(s[i].ID[strlen(s[i].ID)-1] == '\n')
        {
            s[i].ID[strlen(s[i].ID)-1] = '\0';
        }
        if(s[i].cgpa[strlen(s[i].cgpa)] == '\0')
        {
            // s[i].ID[strlen(s[i].ID)-1] = '\0';
            printf("%s","OK");
        }
        
    }
    for (int i = 0; i < 10; ++i)
    {
        printf("%s - %s\n",s[i].ID,s[i].cgpa);
        printf("%d\n",strlen(s[i].cgpa));
    }
    free(s);
    
}