#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory not available\n");
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL)
        printf("Stack is Empty\n");
    else {
        struct node *temp = top;
        printf("Popped: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    struct node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Stack: ");
    display();

    pop();

    printf("Stack after pop: ");
    display();

    return 0;
}
