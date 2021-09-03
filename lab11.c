#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    //if it is the first node
    if (front == NULL && rear == NULL)
        //make both front and rear points to the new node
        front = rear = temp;
    else
    {
        rear->next = temp;

        //make the temp as the rear node
        rear = temp;
    }
}

int dequeue()
{
    //used to free the first node after dequeue
    struct node *temp;
    int removedElement;

    if (front == NULL)
    {
        removedElement = INT_MIN;
    }
    else
    {
        //take backup
        temp = front;

        //make the front node points to the next node
        //logically removing the front element
        front = front->next;

        //if front == NULL, set rear = NULL
        if (front == NULL)
        {
            rear = NULL;
        }
        removedElement = temp->data;
        //free the first node
        free(temp);
    }
    return removedElement;
}

void printList()
{
    struct node *temp = front;
    if (temp == NULL)
    {
        printf("Queue is empty!! Nothing to show\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, enqueueElement, dequeueElement, temp;
    do
    {
        printf("\nEnter the operation you want to perform\nPress 1 for enqueueing an element in the queue\nPress 2 for dequeueing an element in the queue\nPress 3 for printing the elements in the queue\nPress 4 for quitting the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to enqueue\n");
            scanf("%d", &enqueueElement);
            enqueue(enqueueElement);
            break;
        case 2:
            temp = dequeue();
            if (temp == INT_MIN)
            {
                printf("Queue is Empty. Unable to perform dequeue operation\n");
            }
            else
            {
                printf("%d was dequeued successfully\n", temp);
            }

            break;
        case 3:
            printList();
            break;
        case 4:
            printf("Quitting the program\n");
            break;

        default:
            printf("Wrong Choice Entered !!\n");
            break;
        }
        printf("\nPress enter to continue... \n");
        getch();
    } while (choice != 4);

    return 0;
}