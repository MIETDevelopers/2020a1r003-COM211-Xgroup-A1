#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data, dataPriority;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d, int priority) //Insert the element and priority in Queue
{
    struct node *temp;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->dataPriority = priority;

    if ((front == NULL) || (front->dataPriority > priority))
    // if (front == NULL)
    {
        ptr->next = front;
        front = ptr;
    }
    else
    {
        temp = front;
        while ((temp->next != NULL) && ((temp->next->dataPriority) <= priority))
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
void print() //Print the data of Queue
{
    struct node *temp = front;
    if (temp == NULL)
    {
        printf("The queue is empty and there is nothing to show\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("\nData = %d\tPriority = %d ", temp->data, temp->dataPriority);
            temp = temp->next;
        }
    }
}
int dequeue() //Deletion of highest priority element from the Queue
{
    int removed;
    struct node *temp;
    if (front == NULL) //Check for Underflow condition
    {
        removed = INT_MIN;
    }
    else
    {
        temp = front;
        front = front->next;
        printf("\nDeleted element:- %d\t and Its Priority:- %d", temp->data, temp->dataPriority);
        removed = temp->data;
        free(temp);
    }
    return removed;
}
int main()
{
    int choice, data, priority, temp;
    do
    {
        printf("\nEnter the operation you want to perform\nPress 1 for enqueueing an element in the queue\nPress 2 for dequeueing an element in the queue\nPress 3 for printing the elements in the queue according to its priorities\nPress 4 for quitting the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("\nEnter your data \n");
            scanf("%d", &data);
            printf("\nEnter data priority\n");
            scanf("%d", &priority);
            enqueue(data, priority);

            break;
        case 2:
            temp = dequeue();
            if (temp == INT_MIN)
            {
                printf("Queue is Empty. Unable to perform dequeue operation\n");
            }
            else
            {
                printf("\n%d was dequeued successfully\n", temp);
            }

            break;
        case 3:
            print();
            break;
        case 4:
            printf("Quitting the program\n");
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (choice != 4);
    return 0;