#include <cs50.h>
#include <stdio.h>

float average (int length, int array[]);
int main(void)
{   //get number of scores

    int n = get_int("scores:  ");
    //get scores


    int scores[n];
    for (int i=0 ; i<n ; i++)

    { //each score ask
        scores[i] = get_int("score %i:  ", i+1);
    }
    printf("Average: %.1f \n", average(n, scores));
}

float average (int length, int array[]) // same as (int n, int scores[]);
{
    int sum = 0;
    for (int i=0 ; i<length ; i++)
    {
        sum = sum + array[i];
    }
    return (float)sum/(float)length;
}