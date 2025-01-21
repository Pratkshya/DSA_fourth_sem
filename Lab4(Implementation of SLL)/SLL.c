#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct  SLL *next;

};
struct SLL *first, *last=NULL;
struct SLL* create_node(int element)
{
    struct SLL *newNode;
    newNode = (struct SLL*) malloc(sizeof(struct SLL));
    if (newNode != NULL)
    {
        newNode -> data = element;
        newNode -> next = NULL;
    }
    return newNode;
};
void insert_at_the_beginning(int element)
{
    struct SLL *newNode = create_node(element);
    if (newNode == NULL)
    {
        printf("Memort Allocation Failed\n");
    }
    else
    {
        if(first == NULL)
            first = last = newNode;
        else
        {
            newNode -> next = first;
            first = newNode;
        }
    }
}
void insert_at_the_end(int element)
{
    struct SLL *newNode = create_node(element);
    if (newNode == NULL)
    {
        printf("Memort Allocation Failed\n");
    }
    else
    {
        if(first == NULL)
            first = last = newNode;
        else
        {
            last -> next = newNode;
            last = newNode;
        }
    }
}
void insert_at_the_specific_position(int element, int position)
{
    struct SLL *newNode;
    struct SLL *temp;
    newNode = (struct SLL*) malloc(sizeof(struct SLL));
    newNode -> data = element;
    newNode -> next = NULL;
    if(position == 1)    
    {
        newNode -> next = first;
        first = newNode;
    }
    else
        temp = first;
        for(int i = 1; i < position - 1; i++)
        {
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
        printf("%d is inserted\n", newNode -> data);
}

void delete_at_the_beginning()
{
    struct SLL *temp = first;
    if(first == NULL)
        printf("List is empty\n");
    else if (first -> next == NULL)
    {
        first = last = NULL;
        printf("%d is going to be deleted\n", temp -> data);
        free(temp);
    }  
    else
    {
        temp = first;
        first = first -> next;
        printf("%d is deleted\n", temp -> data);
        free(temp);
    }  
}
void deletion_at_the_end()
{
    struct SLL *temp = first;
    if(first == NULL)
        printf("List is empty\n");
    else if (first -> next == NULL)
    {
        first = last = NULL;
        printf("%d is going to be deleted\n", temp -> data);
        free(temp);
    }  
    else
    {
        while (temp -> next != last)
            {
                temp = temp -> next;
            }
            last = temp;
            temp = last -> next;
            free(temp);
            last -> next = NULL;
    }
    
}
void display()
{
    struct SLL *temp = first;
    if(first == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        } while (temp != NULL);
        printf("NULL\n");
        
    }
}
void searching(int element)
{
    struct SLL *temp = first;
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
int main()
{
    insert_at_the_beginning(100);
    display();
    insert_at_the_beginning(200);
    display();
    insert_at_the_beginning(500);
    display();
    insert_at_the_specific_position(600, 3);
    display();
    delete_at_the_beginning();
    display();
    deletion_at_the_end();
    display();
    searching(500);
    display();
    return 0;
}

