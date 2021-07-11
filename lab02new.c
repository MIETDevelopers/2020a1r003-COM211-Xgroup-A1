// used arjun charak's code
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack
{
   int *data;
   int maxSize; // maximum size of the stack.
   int top; //initially the size of the stack is 0.
};
// we are creating a function to check whether the stack is empty or not.
int isEmpty(struct Stack *stack)
{
   if(stack->top == -1){      //if value comes out be -1 it means that there is nothing in the stack
      return 1;
   }
   else{
      return 0;
   }
}
//we are  creating a function to check whether the stack is full or not.
int isFull(struct Stack *stack)
{
   if(stack->top == stack->maxSize - 1)  // it means the stack is full
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
//we are creating a function to push an element into the stack.
int push(struct Stack *stack, int value)
{
   if(isFull(stack))
   {
      printf("\nStack Overflow\n");
   }
   else
   {
      stack->top++;   // the new element will be pushed into the stack from the top
      stack->data[stack->top] = value;    //value will change since a new element has been added to the top 
      printf("\nElement pushed successfully\n");
   }
}
// we are creating a function to pop the top element from the stack.
int pop(struct Stack *stack, int value)
{
   if(isEmpty(stack))
   {
      printf("\nStack Underflow\n");
      return INT_MIN;     //it will return the minimum value present in the stack which in this case shows that there is nothing in the stack
   }
   else
   {
      value = stack->data[stack->top];
      stack->top--;  // the desired element gets popped off so the size of the stack decreases
      return value;
   }
}
// we are creating a function to display all the elements of the stack.
void peek(struct Stack *stack) // using void peek here so that to get the topmost element of the stack.
{
   int top;
   if (isEmpty(stack))
   {
      printf("\nStack is empty! \n");
   }
   else
   {
      printf("\nElements in the stack are :\n");
      top = stack->top;
      while (top != -1)  //it will show all the values present in the stack from the top
      {
         printf("%d \n", stack->data[top]);
         --top;
      }
   }
}
// creating a new function to display the top element of the stack.
int topStack(struct Stack *stack)
{
   int top;
   if (isEmpty(stack))
   {
      printf("\nStack is empty! \n");
   }
   else{
      return top = stack->data[stack->top];     // this will show the element present at the top of the stack
   }
}
int main()
{
   int value, operation, top, maxSize;
   printf("\nEnter the size of the stack :");
   scanf("%d", &maxSize);
   // creating a new structure with the name stackA by using dynamic memory allocation (malloc)
   struct Stack *stackA = (struct Stack *)malloc(sizeof(struct Stack));
   stackA->maxSize = maxSize;
   stackA->top = -1;   // top = -1 means the top is at the index -1 and there is no element in the stack.
   stackA->data = (int *)malloc(stackA->maxSize * sizeof(int));
   do
   {
      printf("\nChoose an operation\n");
      printf("1.Push In Stack\n");
      printf("2.Pop From Stack\n");
      printf("3.Display All Elements of Stack\n");
      printf("4.Display Top Element of Stack\n");
      printf("5.Exit\n");
      scanf("%d", &operation);
      switch (operation){
         case 1:
            printf("\nEnter the element to be pushed\n");
            scanf("%d", &value);
            push(stackA, value);    // calling the push function here
            break;
         case 2:
            printf("\nPop out the element\n");
            int popped = pop(stackA,value); // calling the pop function here
            if (stackA->top == INT_MIN)   // for the case if the stack is empty
            {
               return INT_MIN;
            }
            else
               printf("%d popped from the stack \n", popped);
            break;
         case 3:
            peek(stackA);       // calling the peek function here
            break;
        case 4:
            printf("\nElement at the top of the Stack is %d\n", topStack(stackA));   // calling the top function here
            break;
         case 5:
            printf("\nPress enter to exit\n");
            exit(0);
            break;
         default:
            printf("\nWrong operation\n");
            break;
      }
   }
   while (1);
   return 0;
}