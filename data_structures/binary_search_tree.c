#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Tree Node here
typedef struct Node
{
    int value;
    // Pointers to the left and right children
    struct Node *left;
    struct Node *right;
} Node;

Node *init_tree(int data);
Node *create_node(int data);
bool search_tree(Node *root, int num);
void print_tree(Node *root);
unsigned long long sum_tree(Node *root);
void free_tree(Node *root);
unsigned long long tree_height(Node *root);

int main()
{
    // Program to demonstrate finding the height of a Binary Tree

    // Create the root node having a value of 10
    Node *root = init_tree(29);

    // Build a sorted binary search tree
    root->left = create_node(15);
    root->right = create_node(40);
    root->left->left = create_node(7);
    root->left->right = create_node(18);

    // Print nodes of the tree
    print_tree(root);

    // Search tree for numbers
    printf("%i\n", search_tree(root, 100));
    printf("%i\n", search_tree(root, 18));

    // Print the sum of integer values in the tree
    printf("Sum of element in Binary Tree: %llu\n", sum_tree(root));

    // Find the height of the tree
    int height = tree_height(root);
    printf("Height of the Binary Tree: %d\n", height);

    // Free the tree!
    free_tree(root);
    return 0;
}

Node *init_tree(int data)
{
    // Creates the tree and returns the
    // root node
    Node *root = (Node *)malloc(sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}

Node *create_node(int data)
{
    // Creates a new node
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool search_tree(Node *root, int num)
{
    if (root == NULL)
    {
        return false;
    }
    else if (num < root->value)
    {
        return search_tree(root->left, num);
    }
    else if (num > root->value)
    {
        return search_tree(root->right, num);
    }
    else
    {
        return true;
    }
}

void print_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    print_tree(root->left);
    printf("%i\n", root->value);
    print_tree(root->right);
}

unsigned long long sum_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    unsigned long long sum = 0;
    sum += sum_tree(root->left);
    sum += root->value;
    sum += sum_tree(root->right);

    return sum;
}

void free_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

unsigned long long tree_height(Node *root)
{
    // Get the height of the tree
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Find the height of both subtrees
        // and use the larger one
        unsigned long long left_height = tree_height(root->left);
        unsigned long long right_height = tree_height(root->right);

        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}