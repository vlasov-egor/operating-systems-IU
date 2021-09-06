#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *Create(int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void print_list(struct Node *head)
{
    struct Node *current = head;
    while (current->next != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("%d ", current->value);
}

void *insert_node(struct Node *existing, struct Node *new_node)
{
    if (existing->next != NULL)
        new_node->next = existing->next;

    existing->next = new_node;
}

int delete_node(struct Node *head, struct Node *deleted)
{
    struct Node *current = head;

    while (current->next != deleted && current->next != NULL)
    {
        current = current->next;
    }
    current->next = deleted->next;
    int result = deleted->value;
    free(deleted);
    return result;
}

int main()
{
    struct Node *zero_linked_list_element = Create(0);

    struct Node *el1 = Create(1);
    struct Node *el2 = Create(2);
    struct Node *el3 = Create(3);
    struct Node *el4 = Create(4);
    struct Node *el5 = Create(5);

    insert_node(zero_linked_list_element, el1);
    insert_node(el1, el2);
    insert_node(el2, el3);
    delete_node(zero_linked_list_element, el3);
    insert_node(el3, el4);
    insert_node(el2, el5);

    print_list(zero_linked_list_element);
}