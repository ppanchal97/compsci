#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int votes;
} candidate;

const int MAX = 9;

int initialize_voting(candidate candidates[], int candidate_count);
int vote(candidate candidates[], int candidate_count, char *name);
int print_winner(candidate candidates[], int candidate_count);

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 9)
    {
        printf("err: please enter between 1 and 9 candidates");
        return 1;
    }

    const int candidate_count = argc - 1;

    candidate candidates[candidate_count];

    // process candidates in argv[]
    for (int i = 0 + 1; i < argc; i++)
    {
        // initialize
        candidates[i - 1].name = argv[i];
        candidates[i - 1].votes = 0;
    }

    initialize_voting(candidates, candidate_count);

    print_winner(candidates, candidate_count);

    return 0;
}

int initialize_voting(candidate candidates[], int candidate_count)
{
    // take number of voters
    int voter_count;
    printf("Number of voters: ");
    scanf("%i", &voter_count);

    // take votes for the number of voters
    for (int i = 0; i < voter_count; i++)
    {
        // take name
        char *name = malloc(256);
        printf("Vote: ");
        scanf("%s", name);

        vote(candidates, candidate_count, name);
    }

    return 0;
}

int vote(candidate candidates[], int candidate_count, char *name)
{
    // find candidate and increment vote count for that name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // found, increment vote
            candidates[i].votes += 1;
        }
    }

    return 0;
}

int print_winner(candidate candidates[], int candidate_count)
{
    int most_votes = 0;

    // iterate to find max number of votes
    for (size_t i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > most_votes)
        {
            most_votes = candidates[i].votes;
        }
    }

    // iterate to find candidate who's vote matches max_votes
    for (size_t i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == most_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return 0;
}