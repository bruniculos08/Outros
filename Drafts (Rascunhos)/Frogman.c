#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void){
    
    int i;
    int k;
    int a;
    int const N; //total numeber of people
    int const R; //number of people that came back

    printf("put the total number of people: ");
    scanf("%i", &N);
    
    if(N<=0)
    {
        printf("ERROR");
        return 0;
    }

    printf("put the total number of people that came back: ");
    scanf("%i", &R);

    if(R<=0)
    {
        printf("ERROR");
        return 0; 
    }

    int id[R];
    int count[N];

    for (i=0; i<N; i++)
    {
        count[i] = i+1;
    }

    for (i=0 ; i<R ; i++)
    {
        printf("insert an id: ");
        scanf("%i", &id[i]);
    }
    
    printf("the id of the members that didn't came back are: ");

    for (k=0; k<N; k++)
    {
        a=0;
        for (i = 0; i < R; i++)
        {
            if (id[i] == count[k])
            {
                a++;
            }
        }
        
        if(a==0)
        {
            printf("%i ", count[k]);
        }

    }
    
}