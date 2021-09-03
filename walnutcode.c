#include<stdio.h>
#include<stdlib.h>
struct info
{
char name[50];
int price;
struct info *next;
};
struct info *temp,*disp,*head;
void addrecord();
void display();
void displaymin();
void displaymax();
void deleterecord();
int main()
{
  int ch, ch1;
  while (1) 
    {
      printf("\n~Walnuts tracker~\n");
      printf("\n 1. To add records.");
      printf("\n 2. To delete records.");
      printf("\n 3. To view the records.");
      printf("\n 4. To exit.");
      printf("\n Enter your choice: ");
      scanf("%d",&ch);       
      fflush(stdin);
      switch(ch)
            {
              case 1:
                  addrecord();
                      break;

              case 2:
                  deleterecord();
                    break;
              
              case 3:
                  printf("\n1. Display whole list.");
                  printf("\n2. Display minimum price.");
                  printf("\n3. Display maximum price.");
                  printf("\n Enter choice: ");
                  scanf("%d", &ch1);
                  switch(ch1)
                  {
                    case 1:
                      display();
                        break;

                    case 2:
                      displaymin();
                        break;

                    case 3:
                      displaymax();
                        break;

                    default:
                      printf("\n Invalid choice! :/");
                        break;
                  }
                      break;

              case 4:
                  exit(0);
                      break;

              default:
                  printf("Invalid choice! :/");
                    break;
            }
    }
return 0;
}
void addrecord()
{
  struct info *add;
  add=(struct info*)malloc(sizeof(struct info));
  printf("\n Enter the name of dealer: ");
  gets(add->name);
  fflush(stdin);
  printf("\n Enter the price of Walnuts: ");
  scanf("%d",&add->price);
  fflush(stdin);

    if(head==NULL|| head->price>=add->price)
      {
        add->next=head;
        head=add;
      }
    else
      {
        temp=head;
          
          while(temp->next!=NULL && temp->next->price < add->price)
            {
              temp=temp->next;
            }
        add->next=temp->next;
        temp->next=add;
      }

  return;
 }

void display()
{
  int count=0;
  if(head==NULL)
    {
      printf("\n No records to view\n");
      return;
    }

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      printf("\n -- \nSerial number: %d", count);
      printf("\nName of dealer: %s",disp->name);
      printf("\nPrice of Walnuts: %d \n",disp->price);
      count++;
    }
  count=0;
return;
}

void deleterecord()
{
    display();
    int i,pos;
    struct info *temp,*ptr;
    if(head==NULL)
    {
        printf("\nThe List is Empty! :/");
        return;
    }
    else
    {
        printf("\nEnter the serial number of record to be deleted: ");
        scanf("%d",&pos);
            if(pos==0)
            {
                ptr=head;
                head=head->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
            else
            {
                ptr=head;
                for(i=0;i<pos;i++) 
                { 
                    temp=ptr; 
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                        printf("\nNode not found :/");
                        return;
                    }
                }
                temp->next=ptr->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
    }
}

void displaymin()
{
  if(head==NULL)
    {
      printf("\n No records to view!\n");
      return;
    }

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      if(disp=head)
      {
        printf("\nName of dealer: %s",disp->name);
        printf("\nPrice of Walnuts: %d \n",disp->price); 
        return; 
      }
    }
return;  
}

void displaymax()
{
  int count1=0, count2=0;
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count1++;
  }

  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count2++;
    if(count1==count2)
    {
    printf("\nName of dealer: %s",disp->name);
    printf("\nPrice of Walnuts: %d \n",disp->price);
    return;
    }
  }
    count1=0;
    count2=0;
}