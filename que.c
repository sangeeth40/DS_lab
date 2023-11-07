//circular queue
#include<stdio.h>
int rear=-1,front=-1,n=5,choice;
int queue[5];

int checkFull (){
  if ((front == rear + 1) || (front == 0 && rear == n - 1))
    {
      return 1;
    }
  return 0;
}

int checkEmpty ()
{
  if (front == -1)
    {
      return 1;
    }
  return 0;
}
void enque(){
int num;
printf("Enter the value: ");
scanf("%d",&num);
if(checkFull())
	printf("\nqueue overflow");
else{
	 if (front == -1)
	front = 0;

      rear = (rear + 1) % n;
      queue[rear] = num;
      printf (" enqueued to circular queue\n");
}

}
void deque(){

  if (checkEmpty())
    {
      printf ("Underflow condition\n");
   
    }
  else
    {
  
      if (front == rear)
	{
	  front = rear = -1;
	}
      else
	{
	  front = (front + 1) % n;
	}
      printf ("dequeued from circular queue\n");
    }
}
void display()
{
  int i;
  if (checkEmpty ())
    printf ("Nothing to dequeue\n");
  else
    {
      printf ("\nThe queue looks like: \n");
      for (i = front; i != rear; i = (i + 1) % n)
	{
	  printf ("%d ", queue[i]);
	}
      printf ("%d \n\n", queue[i]);

    }
}

void main(){
do{
	printf("\nEnter the choice :");
	scanf("%d",&choice);
switch(choice){
	case 1:enque();
	break;
	case 2:deque();
	break;
	case 3:display();
	break;
	case 4:printf("exit");
}

}while(choice!=4);
}

