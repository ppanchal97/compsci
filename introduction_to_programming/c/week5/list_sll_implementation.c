#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

// List interface
int insert_at(node *list, int num, int position);
int prepend(node *list, int num);
int append(node *list, int num);
int delete(node *list, int num);
unsigned int length(node *list);
node *get_head(node *list);
node *get_tail(node *list);

int main(int argc, const char *argv[])
{
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->num = 10;
    n->next = NULL;

    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n->num = 13;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }

    n->num = 17;
    n->next = NULL;

    list->next->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next->next);
        free(list->next);
        free(list);
        return 1;
    }

    n->num = 25;
    n->next = NULL;

    list->next->next->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next->next->next);
        free(list->next->next);
        free(list->next);
        free(list);
        return 1;
    }
    n->num = 59;
    n->next = NULL;

    list->next->next->next->next = n;

    insert_at(list, 15, 2);
    prepend(list, 5);
    delete (list, 13);
    append(list, 90);

    // print list;
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->num);
    }

    // free all items in the list;

    return 0;
}

int insert_at(node *list, int num, int position)
{
    if (position == 0)
    {
        printf("err: use prepend instead\n");
        return 1;
    }

    int idx = 0;
    node *tmp = list;

    while (idx != position - 1)
    {
        tmp = tmp->next;
        idx++;
    }

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return -1;
    }

    n->num = num;
    n->next = tmp->next;

    tmp->next = n;

    return 0;
}

int prepend(node *list, int num)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return -1;
    }

    n->num = num;
    n->next = &(*list);
    list = n;

    return 0;
}

int delete(node *list, int num)
{
    // traverse list
    node *tmp = list;
    while (tmp->next->num != num)
    {
        tmp = tmp->next;
    }
    // if next node's num == num
    // store tmp->next->next in a holder variable
    node *holder = tmp->next->next;
    // free tmp->next
    free(tmp->next);
    // set tmp-> next to holder
    tmp->next = holder;

    return 0;
}

int append(node *list, int num)
{
    // traverse list to the end
    node *tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // add new node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return -1;
    }
    // rearrange pointers
    n->num = num;
    n->next = NULL;
    tmp->next = n;
    // return
    return 0;
}

unsigned int length(node *list)
{
    unsigned int counter = 0;

    // traverse the list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        // for each node, increment a counter variable
        counter++;
    }

    // return counter
    return counter;
}

node *get_head(node *list)
{
    return list;
}

node *get_tail(node *list)
{
    return list->next;
}