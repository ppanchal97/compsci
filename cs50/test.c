#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int start_node;
    int end_node;
} pair;

void search_graph(int starting_node);

/*
A <-------|
|-> B     |
|--> C -> D
*/

const int pair_count = 2;
pair pairs[pair_count] = {{0, 1}, {2, 0}};

bool is_looped = false;

int main(void)
{
    search_graph(0);
    printf("is graph looped: %d\n", is_looped);
    return 0;
}

void search_graph(int starting_node)
{
    // starting from given node, for all nodes that given node is connected to, print the nodes they are connected to
    for (int i = 0; i < pair_count; i++)
    {
        if (pairs[i].start_node == starting_node)
        {
            if (pairs[i].end_node == pairs[0].start_node)
            {
                printf("loop\n");
                is_looped = true;
                return;
            }
            
            // print node being pointed to
            printf("%i -> %i\n", pairs[i].start_node, pairs[i].end_node);

            // recursively search from the end node
            search_graph(pairs[i].end_node);
        }
    }
    return;
}