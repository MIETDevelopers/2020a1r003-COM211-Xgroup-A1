// used arjun charak's code
#include <stdio.h>  //using the required header files
#include <stdlib.h>
#include <string.h>  //important for the paranthesis checking  part of the code
#include <limits.h>
struct Stack
{
   char *data;
   int maxSize; // maximum size of the stack.
   int top; //initially size of of the stack is 0.
};
// we are creating a function to check whether the stack is empty or not.
int isEmpty(struct Stack *stack)
{
   if(stack->top == -1){   //if the top is -1, that means the stack is empty
      return 1;
   }
   else{
      return 0;
   }
}
// we are creating a function to check whether the stack is full or not.
int isFull(struct Stack *stack)
{
   if(stack->top == stack->maxSize - 1)   // it means the stack is full
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
// creating a new function to push an element into the stack.
char push(struct Stack *stack, char value)
{
   if(isFull(stack))
   {
      printf("\nStack Overflow\n");
   }
   else
   {
      stack->top++;    //the new element will be pushed into the stack
      stack->data[stack->top] = value;   //the value will also change since there will be increase in the size of the stack
   }
}
// creating a function to pop the top element from the stack.
char pop(struct Stack *stack, char value)
{
   if(isEmpty(stack))
   {
      printf("\nStack Underflow\n");
      return '\0';
   }
   else
   {
      value = stack->data[stack->top];  //the topmost element gets popped off
      stack->top--;  // the size of the stack will change since an element is removed
      return value;
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
      return top = stack->data[stack->top];  //it will scan all the elements and display the topmost
   }
}
int main()
{
   int expressionSize;
   char expression[100];   // expression is simply the size of the stack
   struct Stack stackA;
   stackA.top = -1;   // it means the stack is empty
   printf("\nEnter the expression : \n");
   gets(expression);   // gets() is usedc to store the value in the string
   expressionSize = strlen(expression); // strlen signifies the length of the string
   stackA.maxSize = expressionSize;     // keeping the size of the stack equal to the expression size
   stackA.data = (char *)malloc(stackA.maxSize * sizeof(char));   //dynamically re-allocating memory for new stack
   for (int i = 0; i < expressionSize; i++)   //initializing from index 0 to maximum index
   {
      if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
      {
         push(&stackA, expression[i]);  // a new type of bracket will be pushed in the stack
      }
      if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
      {
         if ((stackA.data[stackA.top] == '(' && expression[i] == ')') || (stackA.data[stackA.top] == '{' && expression[i] == '}') || (stackA.data[stackA.top] == '[' && expression[i] == ']'))
         {
            int temp = pop(&stackA, expression[i]);  //if the bracket is the closing part of the first one, then the pair gets popped off the stack
         }
         else
         {
            return 0;
         }
      }
   }
   if (isEmpty(&stackA))
   {
      printf("\nParenthesis is balanced. \n");
   }
   else
   {
      return 0;
   }
   return 0;
}