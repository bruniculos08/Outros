#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Unencrypted messege: ");
    printf("Crypted messege: ");
    for (int i=0, n=strlen(text) ; i<n ; i++)
    if ((text[i]>= 'a' && text[i]< 'z') || (text[i]>= 'A' && text[i]< 'Z') )
     {
        printf("%c", text[i]+1);

     }
    else
     {
       if (text[i]== 'z' || text[i]== 'Z')
       {
       printf("%c", text[i]-25);
       }
     else
       {
       printf("%c", text[i]);
       }
    }
    printf("\n");
}