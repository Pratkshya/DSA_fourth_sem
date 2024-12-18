#include <stdio.h>
#define Max 5

// Define person as a structure
typedef struct {
    char name[50];
    int age;
} person;

// Define stack as a structure
typedef struct {
    int tos;
    person data[Max];
} stack;

// Initializing stack
void initialiseStack(stack *s) {
    s->tos = -1;
}

// Check if stack is empty
int isEmpty(stack *s) {
    return s->tos == -1;
}

// Check if stack is full
int isFull(stack *s) {
    return s->tos == Max - 1;
}

// Push function
void push(person p, stack *s) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->data[++s->tos] = p;
    }
}

// Pop function
person pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        person null = {"", 0};
        return null;
    } else {
        return s->data[s->tos--];
    }
}

// Peek function
person peek(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Insert some data.\n");
        person null = {"", 0};
        return null;
    }
    return s->data[s->tos];
}

// Display function
void displayStack(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        for (int i = 0; i <= s->tos; i++) {
            printf("\nPerson %d: \n Name: %s,\n Age: %d \n\n", i + 1, s->data[i].name, s->data[i].age);
        }
    }
}

int main() {
    stack s;
    initialiseStack(&s);

    person p1 = {"sheldon", 32};
    person p2 = {"amy", 25};
    person p3 = {"penny", 23};

    printf("\nInitial stack\n");
    displayStack(&s);

    push(p1, &s);
    push(p2, &s);
    push(p3, &s);

    printf("\nNew stack\n");
    displayStack(&s);

    printf("\nPopping stack\n");
    person poppedItem = pop(&s);
    printf("Popped Item: \n Name: %s,\n Age: %d \n", poppedItem.name, poppedItem.age);

    printf("\nAfter popping stack\n");
    displayStack(&s);

    printf("\nPeeking stack\n");
    person peekedItem = peek(&s);
    printf("Peeked Item: \n Name: %s,\n Age: %d \n", peekedItem.name, peekedItem.age);

    return 0;
}
