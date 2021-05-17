#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[4];
    names[0] = "BRUNO";
    names[1] = "ROBERTO";
    names[2] = "OLIVER";
    names[3] = "EMMA";

    int n = get_int("Choose a number between 0 and 3 to see a name: ");
    for (int i=0 ; names[n][i] != '\0' ; i++)
    {
        printf(" %c \n", names[n][i]);
    }
}