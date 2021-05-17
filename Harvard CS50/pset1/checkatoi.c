#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void exit(int status);

int main(int argc, string argv[])
{
    string s = argv[1];
    int n = atoi (argv[1]);
    int c = strlen(s);
    for (int i=0; i<c; i++)
    {
     //int x = atoi (&s[i]);
     if (s[i]>= 'a' && s[i]<= 'z')
     {
         printf("ERROR \n");
         exit(0);
     }
    }
    printf("Good %i \n", n);
}