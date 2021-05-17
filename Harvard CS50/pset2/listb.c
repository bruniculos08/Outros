#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{   int x = 0;
    node *list = NULL;
    node *n = malloc(sizeof(node));
    node *bucket[26];
    bucket[0] = list;


    if (n == NULL)
    {
        return 1;
    }

    n->number = 1;
    n->next = NULL;
    if (bucket[x] != NULL)
    {
        x++;
        bucket[x] = bucket[x-1]->next;
    }
    bucket[x] = n;
    list = n;
    n = malloc(sizeof(node));

    if (n == NULL)
    {
        return 1;
    }

    n->number = 2;
    n->next = NULL;
    if (bucket[x] != NULL)
    {
        x++;
        bucket[x] = bucket[x-1]->next;
    }
    bucket[x] = n;

    n = malloc(sizeof(node));

    if (n == NULL)
    {
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    if (bucket[x] != NULL)
    {
        x++;
        bucket[x] = bucket[x-1]->next;
    }
    bucket[x] = n;

    for (int i = 0; i<=x; i++)
    {
        node *tmp = bucket[i];
        printf("%i\n", tmp->number);
    }

    for (int i = 0; i<x; i++)
    {
        node *tmp = bucket[i];
        free(bucket[i]);
    }
}