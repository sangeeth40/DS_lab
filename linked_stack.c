#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *start = NULL;

void push()
{
    int val;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Not able to push the element");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &val);
        ptr->val = val;
    }

    if (start == NULL)
    {
        ptr->next = NULL;
        start = ptr;
    }
    else
    {
        ptr->next = start;
        start = ptr;
        printf("Item pushed\n");
    }
}

void pop()
{
    int item;
    struct node *ptr;
    if (start == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        item = start->val;
        ptr = start;
        start = start->next;
        free(ptr);
        printf("Item popped: %d\n", item);
    }
}

void display()
{
    struct node *ptr = start;
    if (ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int choice = 0;
    printf("\nStack operations using linked list\n");
    
        printf("\nMenu------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    while (choice != 4)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting....\n");
            break;
        default:
            printf("Please Enter a valid choice\n");
        }
    }

    return 0;
}

