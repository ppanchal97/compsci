#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j

bool is_graph_looped = false;

bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int start_node;
    int end_node;
} pair;

int pair_count;
int candidate_count;

// Array of candidates
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

pair temporary_pairs_graph[MAX * (MAX - 1) / 2];

// Function prototypes
bool vote(int rank, char *name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool is_valid_candidate(char *name);
void search_graph(int starting_node);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;

    int voter_count;
    printf("Number of voters: ");
    scanf("%i", &voter_count);

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char *name = malloc(256);
            printf("Rank %i: ", j + 1);
            scanf("%s", name);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    // handle garbage values
    for (int i = 0; i < (MAX * (MAX - 1) / 2); i++)
    {
        temporary_pairs_graph[i].start_node = -1;
        temporary_pairs_graph[i].end_node = -1;
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

bool is_valid_candidate(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            return true;
        }
    }

    return false;
}

// Update ranks given a new vote
bool vote(int rank, char *name, int ranks[])
{
    // If name is a match for the name of a valid candidate,
    // update the ranks array to indicate that the voter has the candidate as their rank preference
    if (is_valid_candidate(name))
    {
        // get candidate position in candidates array, then insert into rank in ranks array
        for (int i = 0; i < candidate_count; i++)
        {
            if (strcmp(candidates[i], name) == 0)
            {
                // match, record index of candidate
                ranks[rank] = i;
                return true;
            }
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // iterate over ranks using double for loops then increment preferences array's
    // p[i][j] place
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // compare pairs and add to pairs then increment pair count
            if (preferences[i][j] > preferences[j][i])
            {
                pair p = {i, j};
                pairs[pair_count] = p;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pair p = {j, i};
                pairs[pair_count] = p;
                pair_count++;
            }
            else
            {
                // tied
                continue;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int is_swapped = 0;
    for (int i = 0; i < pair_count; i++)
    {
        // terminates at 1 position before the end to avoid comparing last element with one out of the array
        // ..preventing a segfault.
        for (int j = 0; j < pair_count - 1; j++)
        {
            int pair_strength_a = labs(preferences[pairs[j].start_node][pairs[j].end_node] - preferences[pairs[j].end_node][pairs[j].start_node]);
            int pair_strength_b = labs(preferences[pairs[j + 1].start_node][pairs[j + 1].end_node] - preferences[pairs[j + 1].end_node][pairs[j + 1].start_node]);

            if (pair_strength_a < pair_strength_b)
            {
                // swap
                pair holder = {pairs[j].start_node, pairs[j].end_node};
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = holder;
                is_swapped = 1;
            }
        }

        // optimization
        if (is_swapped == 0)
        {
            printf("Array sorted. no swaps made.\n");
            return;
        }
    }

    return;
}

void search_graph(int starting_node)
{
    // starting from given node, for all nodes that given node is connected to, print the nodes they are connected to
    for (int i = 0; i < pair_count; i++)
    {
        if (temporary_pairs_graph[i].start_node == starting_node)
        {
            if (temporary_pairs_graph[i].end_node == temporary_pairs_graph[0].start_node)
            {
                printf("loop\n");
                is_graph_looped = true;
                return;
            }

            // print node being pointed to
            printf("%i -> %i\n", temporary_pairs_graph[i].start_node, temporary_pairs_graph[i].end_node);

            // recursively search from the end node
            search_graph(temporary_pairs_graph[i].end_node);
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{    
    // check if temp graph is looped, if looped, remove last added pair
    for (int i = 0; i < pair_count; i++)
    {
        // add pair to graph
        temporary_pairs_graph[i] = pairs[i];
        // search to see if looped. Always start from first value.
        search_graph(pairs[0].start_node);
        if (is_graph_looped != true)
        {
            // lock in the pair 
            printf("locked %i -> %i\n", pairs[i].start_node, pairs[i].end_node);
        }
        else {
            // remove last added value, reset graph loop and continue to add pairs and search
            temporary_pairs_graph[i].start_node = -1;
            temporary_pairs_graph[i].end_node = -1;
            is_graph_looped = false;
            continue;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

/*
Issues
- graph search needs to happen for all pairs in the pairs array,
not just 0. If pairs = {{0,1}, {2,3}}, search will never be carried out
for the second pair as 0 -> 1, then no pair starts with 1 so search will stop.
IT WORKS WHEN START IS 0;
*/