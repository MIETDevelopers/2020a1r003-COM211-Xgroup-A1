#include <stdio.h>
#include <stdlib.h>

struct stack  // declaring the stack
{
    int maxSize; // maximum size of the stack entered by the user
    int top;     // the index of the recently pushed element 
    char *arr;   // array for storing the expression
};

int isEmpty(struct stack *ptr) // function to check if the stack is empty
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr) // function to chexk if the stack is full 
{
    if (ptr->top == ptr->maxSize - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)   // function for pushing a new element to the stack
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack *ptr)   //   function for popping an element from the stack
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty cannot pop from the stack\n");
    }
    else
    {
        ptr->top--;
    }
}

int parenthesisMatch(char *exp, struct stack *ptr)  // function for checking if the parenthesis is balanced or not 
{

    for (int i = 0; exp[i] != '\0'; i++)   // for loop for traversing through the expression for checking the paranthesis
    {
        if (exp[i] == '(')
        {
            push(ptr, '(');   // pushing the starting parenthesis to the stack
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(ptr))
            {
                return 0;
            }
            pop(ptr);   // popping an element from the stack
        }
    }

    if (isEmpty(ptr))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct stack *stackPointer = (struct stack *)malloc(sizeof(struct stack)); // creating an instance for the struct stack using malloc
    stackPointer->top = -1;
    stackPointer->arr = (char *)malloc(stackPointer->maxSize * sizeof(char));
    int choice;
    do
    {
        printf("\nEnter 1 for performing the parenthesis check\nPress 2 for exiting the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the size of the expression\n");
            scanf("%d", &stackPointer->maxSize);
            printf("Enter the expression\n");
            scanf("%s", stackPointer->arr); 
            if (parenthesisMatch(stackPointer->arr, stackPointer))  // checking what the function returned
            {
                printf("The parenthesis is matching\n");
            }
            else
            {
                printf("The parenthesis is not matching\n");
            }
            break;

        case 2:
            printf("Quitting the program\n");
            break;

        default:
            printf("Enter a valid expression\n");
            break;
        }
    } while (choice != 2);
    free(stackPointer->arr); //Freeing memory
    return 0;
}