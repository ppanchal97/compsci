#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Optimization 1: set fixed size of hash table
const signed int CAPACITY = 50000;

// Defintion for an item
typedef struct Ht_item
{
    char *key;
    char *value;
} Ht_item;

// Linked List definition
typedef struct LinkedList
{
    Ht_item *item;
    struct LinkedList *next;
} LinkedList;

// Hash Table definition
typedef struct HashTable
{
    // array of pointers to items.
    Ht_item **items;
    // array of pointers to buckets (linked-lists)
    LinkedList **overflow_buckets;
    int size;
    int count;
} HashTable;

// Hash Table operations
unsigned long get_index(char *str);
HashTable *ht_create(int size);
Ht_item *ht_create_item(char *key, char *value);
void ht_free_item(Ht_item *item);
void ht_free_table(HashTable *table);
void ht_print_table(HashTable *table);
void ht_insert(HashTable *table, char *key, char *value);
void ht_chain_item(HashTable *table, unsigned long index, Ht_item *item);
char *ht_search_by_key(HashTable *table, char *key);
void ht_delete(HashTable *table, char *key);

// Linked List operations
LinkedList *ll_allocate_node();
LinkedList *ll_insert(LinkedList *list, Ht_item *item);
int ll_delete_by_item_value(LinkedList *list, char *value);
void ll_free_list(LinkedList *list);
LinkedList **ll_create_overflow_buckets(HashTable *table);
void ll_free_overflow_buckets(HashTable *table);

int main(void)
{
    HashTable *ht = ht_create(CAPACITY);
    ht_insert(ht, (char *)"1", (char *)"First address");
    ht_insert(ht, (char *)"2", (char *)"Second address");
    ht_insert(ht, (char *)"Hel", (char *)"Third address");
    ht_insert(ht, (char *)"Cau", (char *)"Fourth address");
    ht_print_table(ht);
    ht_delete(ht, (char *)"1");
    ht_delete(ht, (char *)"Cau");
    ht_print_table(ht);
    ht_free_table(ht);

    return 0;
}

// Hash function with high probability of collisions
unsigned long get_index(char *str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}

// Create a pointer to a new HashTable item
Ht_item *ht_create_item(char *key, char *value)
{
    // Allocate memory for an item and it's elements
    // then assign using function args.
    Ht_item *item = (Ht_item *)malloc(sizeof(Ht_item));
    item->key = (char *)malloc(strlen(key) + 1);
    item->value = (char *)malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}

// Create a new hash table
HashTable *ht_create(int size)
{
    // Creates a new HashTable.
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item **)calloc(table->size, sizeof(Ht_item *));

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    table->overflow_buckets = ll_create_overflow_buckets(table);

    return table;
}

void ht_free_item(Ht_item *item)
{
    // Frees an item.
    free(item->key);
    free(item->value);
    free(item);
}

void ht_free_table(HashTable *table)
{
    // Frees the table.
    for (int i = 0; i < table->size; i++)
    {
        Ht_item *item = table->items[i];

        if (item != NULL)
            ht_free_item(item);
    }

    // Free the overflow bucket lists and its items.
    ll_free_overflow_buckets(table);
    free(table->items);
    free(table);
}

void ht_print_table(HashTable *table)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }

    printf("-------------------\n\n");
}

// Create the item based on the { key: value } pair.
void ht_insert(HashTable *table, char *key, char *value)
{
    // create the item
    Ht_item *item = ht_create_item(key, value);

    // Compute the index based on the hash function.
    unsigned long index = get_index(key);

    // Check if the index is already occupied
    Ht_item *current_item = table->items[index];
    if (current_item == NULL)
    {
        // check if table is full
        if (table->count == CAPACITY)
        {
            fprintf(stderr, "err: ht_insert operation exceeds table capacity");
            free(item);
            return;
        }

        // key does not yet exist, ht_insert into items[index]
        table->items[index] = item;
        table->count++;
    }
    // Handle collision
    else
    {
        // 1. key exists, only update value
        if (strcmp(table->items[index]->key, key) == 0)
        {
            strcpy(table->items[index]->value, value);
            return;
        }
        else
        {
            // 2. new key and value
            ht_chain_item(table, index, item);
            return;
        }
    }
}

// Handle collision by ht_inserting into a linked-list using Separate Chaining.
void ht_chain_item(HashTable *table, unsigned long index, Ht_item *item)
{
    LinkedList *head = table->overflow_buckets[index];

    if (head == NULL)
    {
        // Creates the list.
        head = ll_allocate_node();
        head->item = item;
        table->overflow_buckets[index] = head;
        return;
    }
    else
    {
        // Insert to the list.
        table->overflow_buckets[index] = ll_insert(head, item);
        return;
    }
}

char *ht_search_by_key(HashTable *table, char *key)
{
    // Searches for the key in the HashTable.
    // Returns NULL if it doesn't exist.
    int index = get_index(key);
    Ht_item *item = table->items[index];
    LinkedList *head = table->overflow_buckets[index];

    // Provide only non-NULL values.
    if (item != NULL)
    {
        if (strcmp(item->key, key) == 0)
            return item->value;

        if (head == NULL)
            return NULL;

        item = head->item;
        head = head->next;
    }

    return NULL;
}

void ht_delete(HashTable *table, char *key)
{
    // Deletes an item from the table.
    int index = get_index(key);
    Ht_item *item = table->items[index];
    LinkedList *head = table->overflow_buckets[index];

    if (item == NULL)
    {
        // Does not exist.
        return;
    }
    else
    {
        if (head == NULL && strcmp(item->key, key) == 0)
        {
            // Collision chain does not exist.
            // Remove the item.
            // Set table index to NULL.
            table->items[index] = NULL;
            ht_free_item(item);
            table->count--;
            return;
        }
        else if (head != NULL)
        {
            // Collision chain exists.
            if (strcmp(item->key, key) == 0)
            {
                // Remove this item.
                // Set the head of the list as the new item.
                ht_free_item(item);
                LinkedList *node = head;
                head = head->next;
                node->next = NULL;
                table->items[index] = ht_create_item(node->item->key, node->item->value);
                ll_free_list(node);
                table->overflow_buckets[index] = head;
                return;
            }

            LinkedList *curr = head;
            LinkedList *prev = NULL;

            while (curr)
            {
                if (strcmp(curr->item->key, key) == 0)
                {
                    if (prev == NULL)
                    {
                        // First element of the chain.
                        // Remove the chain.
                        ll_free_list(head);
                        table->overflow_buckets[index] = NULL;
                        return;
                    }
                    else
                    {
                        // This is somewhere in the chain.
                        prev->next = curr->next;
                        curr->next = NULL;
                        ll_free_list(curr);
                        table->overflow_buckets[index] = head;
                        return;
                    }
                }

                curr = curr->next;
                prev = curr;
            }
        }
    }
}

// ========= Linked List Operations =========
// Allocate memory for a Linked List node.
LinkedList *ll_allocate_node()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL)
    {
        return NULL;
    }

    return list;
}

LinkedList *ll_insert(LinkedList *list, Ht_item *item)
{
    // 1. no list, create list
    if (list == NULL)
    {
        LinkedList *head = ll_allocate_node();
        if (head == NULL)
        {
            fprintf(stderr, "err: memory allocation for linked list failed.\n");
            return NULL;
        }
        head->item = item;
        head->next = NULL;
        list = head;
        return list;
    }
    // 2. empty list exists, create node and attach
    else if (list->next == NULL)
    {
        LinkedList *node = ll_allocate_node();
        if (node == NULL)
        {
            fprintf(stderr, "err: memory allocation for linked list failed.\n");
            return NULL;
        }
        node->item = item;
        node->next = NULL;
        list->next = node;
        return list;
    }

    // 3. existing list, append to list
    // traverse list to the end
    LinkedList *tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // add new node
    LinkedList *node = ll_allocate_node();
    if (node == NULL)
    {
        fprintf(stderr, "err: memory allocation for linked list failed.\n");
        return NULL;
    }
    // rearrange pointers
    node->item = item;
    node->next = NULL;
    tmp->next = node;

    // return
    return list;
}

int ll_delete_by_item_value(LinkedList *list, char *value)
{
    // check for empty list
    if (list == NULL)
    {
        return 1;
    }
    LinkedList *tmp = list, *prev = NULL;

    // check for the case when the node to be deleted is the first node
    if (strcmp(tmp->item->value, value) == 0)
    {
        list = tmp->next;
        free(tmp);
        return 0;
    }

    // traverse list
    while (tmp != NULL && tmp->item->value != value)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    // if node was not found
    if (tmp == NULL)
    {
        return 1;
    }

    // if node was found
    prev->next = tmp->next;
    free(tmp);
    return 0;
}

// Free a Linked List using an iterative approach
void ll_free_list(LinkedList *list)
{
    LinkedList *temp = list;

    while (list)
    {
        temp = list;
        list = list->next;
        free(temp->item->key);
        free(temp->item->value);
        free(temp->item);
        free(temp);
    }
}

LinkedList **ll_create_overflow_buckets(HashTable *table)
{
    // Create the overflow buckets; an array of LinkedLists.
    LinkedList **buckets = (LinkedList **)calloc(table->size, sizeof(LinkedList *));

    for (int i = 0; i < table->size; i++)
        buckets[i] = NULL;

    return buckets;
}

void ll_free_overflow_buckets(HashTable *table)
{
    // Free all the overflow bucket lists.
    LinkedList **buckets = table->overflow_buckets;

    for (int i = 0; i < table->size; i++)
        ll_free_list(buckets[i]);

    free(buckets);
}