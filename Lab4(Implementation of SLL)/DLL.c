#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Doubly Linked List (DLL) node
struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
};

struct DLL *first = NULL, *last = NULL;

// Create a new node
struct DLL* create_node(int element)
{
    struct DLL *newNode = (struct DLL*) malloc(sizeof(struct DLL));
    if (newNode != NULL)
    {
        newNode->data = element;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

// Insert at the beginning
void insert_at_the_beginning(int element)
{
    struct DLL *newNode = create_node(element);
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else
    {
        if (first == NULL)
        {
            first = last = newNode;
        }
        else
        {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
    }
}

// Insert at the end
void insert_at_the_end(int element)
{
    struct DLL *newNode = create_node(element);
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else
    {
        if (first == NULL)
        {
            first = last = newNode;
        }
        else
        {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }
}

// Insert at a specific position
void insert_at_the_specific_position(int element, int position)
{
    struct DLL *newNode, *temp;
    newNode = create_node(element);
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else if (position == 1) // Insert at the beginning
    {
        newNode->next = first;
        if (first != NULL)
        {
            first->prev = newNode;
        }
        first = newNode;
        if (last == NULL)
        {
            last = newNode;
        }
    }
    else
    {
        temp = first;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            newNode->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            else
            {
                last = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        else
        {
            printf("Invalid position\n");
        }
    }
}

// Delete at the beginning
void delete_at_the_beginning()
{
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct DLL *temp = first;
        if (first->next == NULL) // Only one node
        {
            first = last = NULL;
        }
        else
        {
            first = first->next;
            first->prev = NULL;
        }
        printf("%d is deleted\n", temp->data);
        free(temp);
    }
}

// Delete at the end
void delete_at_the_end()
{
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct DLL *temp = last;
        if (first->next == NULL) // Only one node
        {
            first = last = NULL;
        }
        else
        {
            last = last->prev;
            last->next = NULL;
        }
        printf("%d is deleted\n", temp->data);
        free(temp);
    }
}

// Display the list
void display()
{
    struct DLL *temp = first;
    if (first == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Search for an element
void searching(int element)
{
    struct DLL *temp = first;
    int position = 1;
    int found = 0;

    while (temp != NULL)
    {
        if (temp->data == element)
        {
            printf("Element %d found at position %d\n", element, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
    {
        printf("Element %d not found in the list\n", element);
    }
}

// Main function to test the doubly linked list
int main()
{
    insert_at_the_beginning(100);
    display();
    insert_at_the_beginning(200);
    display();
    insert_at_the_end(300);
    display();
    insert_at_the_specific_position(400, 2);
    display();
    delete_at_the_beginning();
    display();
    delete_at_the_end();
    display();

    printf("Searching for 400...\n");
    searching(400);

    printf("Searching for 500...\n");
    searching(500);

    return 0;
}
