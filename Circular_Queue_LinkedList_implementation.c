#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *rear=NULL;
struct node *front=NULL;

int IsEmpty()
{
if(rear == NULL && front == NULL)
return 1;
else
return 0;
}


void enqueue(int data)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=front;
if(rear==NULL)
{
front=rear=newnode;
rear->next=front;
}
else
{
rear->next=newnode;
rear=newnode;
rear->next=front;
}
}


void dequeue()
{
struct node *temp=front;
if(IsEmpty())
{
printf("Queue is Underflow........");
}
else if(rear==front)
{
rear=front=NULL;
free(temp);
}
else
{
front=front->next;
rear->next=front;
free(temp);
}
}

void peek()
{
if(IsEmpty())
{
printf("Queue is Underflow........");
}
else
{
printf("Element At Peek : %d  ",front->data);
}
}


void print()
{
struct node *temp=front; 
if(IsEmpty())
{
printf("Queue is Underflow........");
}
else
{
while(temp->next!=front)
{
printf("  %d  ",temp->data);
temp=temp->next;
}
printf("  %d  ",temp->data);
}
}


int main()
{
int choice,data;
while(1)
{
printf("\n 1 : Enqueue ");
printf("\n 2 : Dequeue ");
printf("\n 3 : Print Top element : ");
printf("\n 4 : Print all element : ");
printf("\n 5 : Quit ");



printf("\nEnter Your Choice :");
scanf("%d",&choice);

switch (choice)
{
case 1:
    printf("Enter Data : ");
    scanf("%d",&data);
    enqueue(data);
    printf("\nElement in list :");
    print();
    break;

case 2:
    dequeue(); 
    printf("\nElement in list :");
    print();
    break;

case 3: 
    peek();
    break;

case 4:
    print();
    break;

case 5:
    exit(0);
    break;

default:
    printf("Enter Valid Choice : ");
    break;
}
int YES;
printf("\n DO YOU WANT TO CONTINUE YES=1 & NO=0 :");
scanf("%d",&YES);
if(YES==0)
{
exit(0);
}
}
   
return 0;
}