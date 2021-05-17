#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *word = malloc(10*sizeof(char));
    FILE *file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("error\n");
        //return false;
    }
    for (fscanf(file, "%s", word); fgetc(file) != EOF ; fscanf(file, "%s", word))
    {
        char letter = word[0];
        printf("%c\n", letter);
        word = malloc(10*sizeof(char));
    }
    return 0;
}


//int main(void)
//{
  //  int n = 50;
  //  int *p = &n;
 //   printf("%i\n", *p);
 //   printf("%p\n", p);
//}

