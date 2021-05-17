#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[]) //argc and argv are two variables that our main function will now get,
{      string s = argv[1];
    int n = atoi (argv[1]);
    int c = strlen(s);                                  //when our program is run from the command line.
    if (argc != 2)                                     //argc is the argument count, or number of arguments,
    {                                                  //and argv is an array of strings that are the arguments.
    printf("Usage: ./caesar key\n");
    return 1;
    }                                              //argc is the argument count, or number of arguments, //and argv is an array of strings that are the arguments.
    else
    {
     for (int i=0; i<c; i++)
     {
       if (s[i]>= 0 && s[i]<= 9)
        {
         printf("Usage: ./caesar key\n");
        return 1;
        }
       else
        {
        string p = get_string("Plaintext:  ");
         printf("\nCiphertext: ");
         int l = strlen(p);
         for (int j=0 ; j<l ; j++)
         if ((p[j]>= 'a' && p[j]<= 'z')||(p[j]>= 'A' && p[j]<= 'Z'))
            {
            printf("%c", p[j]+n);
            }
         else
         {
             printf("%c", p[j]);
        }
    printf("\n");
     }
    }
  }

