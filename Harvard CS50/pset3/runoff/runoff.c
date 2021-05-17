#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;


// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    int i = voter;
    int j = rank;
    int x;
    for (x=0; x<candidate_count; x++ )
    if (strcmp(name, candidates[x].name)==0)
    {
      if (candidates[x].eliminated == false)
      {
        preferences[i][j]=x;
        //printf("i=%i, j=%i, preferences=%i\n", i, j, preferences[i][j]);
        return true;
      }
    }
    while (x<candidate_count);
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int j;
    int x;
    int i;
    for(i=0; i<voter_count; i++)
    {
            j=0;
            printf("j=%i \n", j);
            x = preferences[i][j];
            if (candidates[x].eliminated == true)
            {
                do
                {
                j = j+1;
                printf("j=%i \n", j);
                x = preferences[i][j];
                }
                while (candidates[x].eliminated == true);
            }
            //while (candidates[x].eliminated == true);
            candidates[x].votes = candidates[x].votes+1;
            //printf("j=%i \n", j);
            j=0;
            printf("votes of %s = %i\n", candidates[x].name, candidates[x].votes);
    }
    while(i<voter_count);
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int i;
    float v = (voter_count)/2;
    for (i=0; i<candidate_count; i++)
    {
     if ((float)candidates[i].votes > v)
     {

            printf("%s\n", candidates[i].name);
            return true;
     }
    }
    while (i<candidate_count);
   // printf("no winner\n");
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int n = candidate_count;
    int i;
    int m = voter_count;
    for (i=0 ; i<n; i++)
    if (candidates[i].eliminated == false)
    {
        if (candidates[i].votes < m)
        {
            m = candidates[i].votes;
        }
    }
    while (i<n);
    //printf("min = %i\n", m);
    return m;
    // TODO
    //return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{

    int p1=0; // criar para quando todos são min
    int n = candidate_count;
    int i;
    int r = n; //rest
    for (i=0; i<=n ; i++)
    {
     if (candidates[i].eliminated == true)
     {
         r = r-1;
     }
     if (candidates[i].eliminated == false)
     {
        if (candidates[i].votes == min)
        {
        p1 = p1+1;
        //printf("p1=%i \n", p1);
        }
     }
    }
  while(i<=n);
  if (p1==r)
        {
        //printf("p1=%i \ntied\n", p1);
        return true;
        }
  return false;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    int n = candidate_count;
    int i;
    for (i=0; i<n; i++)
    {
        if (candidates[i].votes<=min)
        {
            candidates[i].eliminated = true;
            //printf("eliminated: %s\n", candidates[i].name);
        }
    }
    // TODO
    return;
}
