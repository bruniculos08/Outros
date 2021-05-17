#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int phrase(int key);

int main(int argc, string argv[])
{
 if (argc == 2)
 {
  string s=argv[1];
  int n=strlen(argv[1]);
  for (int i=0; i<n ; i++)
  if(s[i]>='0' && s[i]<='9')
  {
   int k = atoi(argv[1]);
   if (i == n-1)
   {
    phrase(k);
   }
  }
  else
  {
   printf("Usage:./caesar key \n");
  }
 }
 else
 {
  printf("Usage: ./caesar key\n");
  return 1;
 }
}




int phrase(int key)
{
 string p = get_string("plaintext: ");
 printf("ciphertext: ");
 int n=strlen(p);
 int i=0;
 for (i=0; i<n ; i++)
 {
  if (isalpha (p[i]))
  {
   if (islower (p[i]))
   {
    p[i] = 96 + (p[i]-96+key)%26;
    printf("%c", p[i]);
   }
   if (isupper (p[i]))
   {
    p[i] = 64 + (p[i]-64+key)%26;
    printf("%c", p[i]);
   }
  }
  else
  {
   p[i] = p[i];//p[i];
   printf("%c", p[i]);
  }
 }
 while (i<n-1);
 printf("\n");
 exit(0);
}