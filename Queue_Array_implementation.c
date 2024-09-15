#include<stdio.h>
#include<stdlib.h>
# define size 5
int queue[5];
int front=-1;
int rear=-1;

int IsEmpty()
{
if(rear == -1 && front == -1)
return 1;
else
return 0;
}

int IsFull()
{
if(rear == size-1)
return 1;
else
return 0;
} 

void enqueue(int x)
{
if(IsFull())
{
printf("Queue is Overflow........");
}
else if(IsEmpty())
{
front=rear=0;
queue[rear]=x;
}
else
{
rear++;
queue[rear]=x;
}
}


void dequeue()
{
if(IsEmpty())
{
printf("Queue is Underflow........");
}
else if(rear == front)
{
front=rear=-1;
}
else
{
printf("Element is deleted  :  %d  ",queue[front]);
front++;
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
printf("Element At Peek : %d  ",queue[front]);
}
}


void print()
{
if(IsEmpty())
{
printf("Queue is Underflow........");
}
else
{
for(int i=front ; i<rear+1 ; i++)
{
printf("  %d  ",queue[i]);
}
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