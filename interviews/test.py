
expectedOutput = """\
==== Just Falafs ====
      ~ Menu ~
Starters
dumplings, peanuts or salad
Mains
bento, sushi, pasta or rice
Desserts
apples, strawberries or cheese
"""

food_categories = {
    "starters": [
        "peanuts", "bread", "salad", "dumplings"
    ],
    "mains": [
        "steak", "bento", "chicken", "pizza", "sandwich", "taco", "sushi",
        "burger", "hotdog", "pasta", "wrap", "rice"
    ],
    "desserts": [
        "apples", "strawberries", "cheese", "icecream", "pie", "cake"
    ]
}

chef_dishes = [
    "strawberries", "dumplings", "pasta", "rice", "apples", "salad", "peanuts",
    "cheese", "bento", "sushi"
]


print("==== Just Falafs ====")
print("       ~ Menu ~      ")
for category, foods in food_categories.items():
    allowed_foods = []
    for food in foods:
        if food in chef_dishes:
            allowed_foods.append(food)
    # print
    print(category[0].upper(), end="")
    print(category[1:])
    if(len(allowed_foods) > 1):
        for i in range(len(allowed_foods) - 2):
            print(f"{allowed_foods[i]}, ", end="")
    
        print(f"{allowed_foods[len(allowed_foods) - 2]} or {allowed_foods[len(allowed_foods) - 1]} ")


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* EXPECTED OUTPUT
==== Just Falafs ====
      ~ Menu ~
Starters
dumplings, peanuts or salad
Mains
bento, sushi, pasta or rice
Desserts
apples, strawberries or cheese
*/

bool linear_search(char *food, char *foods[], int foods_count);

typedef struct
{
    char *name;
    char *foods[20];
    int food_count;
} food_category;

food_category food_categories[3];

char *chef_dishes[10] = {"strawberries", "dumplings", "pasta", "rice", "apples", "salad", "peanuts", "cheese", "bento", "sushi"};

int main(void)
{
    food_categories[0].name = "starters";
    food_categories[0].foods[0] = "peanuts";
    food_categories[0].foods[1] = "bread";
    food_categories[0].foods[2] = "salad";
    food_categories[0].foods[3] = "dumplings";
    food_categories[0].food_count = 4;

    food_categories[1].name = "mains";
    food_categories[1].foods[0] = "steak";
    food_categories[1].foods[1] = "bento";
    food_categories[1].foods[2] = "chicken";
    food_categories[1].foods[3] = "pizza";
    food_categories[1].foods[4] = "sandwich";
    food_categories[1].foods[5] = "taco";
    food_categories[1].foods[6] = "sushi";
    food_categories[1].foods[7] = "burger";
    food_categories[1].foods[8] = "hotdog";
    food_categories[1].foods[9] = "pasta";
    food_categories[1].foods[10] = "wrap";
    food_categories[1].foods[11] = "rice";
    food_categories[1].food_count = 12;


    food_categories[2].name = "desserts";
    food_categories[2].foods[0] = "apples";
    food_categories[2].foods[1] = "strawberries";
    food_categories[2].foods[2] = "cheese";
    food_categories[2].foods[3] = "icecream";
    food_categories[2].foods[4] = "pie";
    food_categories[2].foods[5] = "cake";
    food_categories[2].food_count = 6;


    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", food_categories[i].name);
        for (int j = 0; j < food_categories[i].food_count; j++)
        {
            printf("%s ", food_categories[i].foods[j]);
            if(linear_search(food_categories[i].foods[j], food_categories[i].foods, food_categories[i].food_count) == true)
            {
                // found
                printf("%s ", food_categories[i].foods[j]);
            }
            else
            {
                printf("");
            }
        }
        printf("\n");
    }
}

bool linear_search(char *food, char *foods[], int foods_count)
{
    bool is_found = false;

    for (int i = 0; i < foods_count; i++)
    {
        if(strcmp(food, foods[i]) == 0)
        {
            is_found = true;
        }
    }

    return is_found;
}