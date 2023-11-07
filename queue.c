#include<stdio.h>
void insert();
void display();
void delete();
int arr[50], rear=-1,front=-1,n;

int main(){
int choice;
printf("Enter the size :");
scanf("%d",&n);
do{
	printf("\nEnter the choice :");
	scanf("%d",&choice);
switch(choice){
	case 1:insert();
	break;
	case 2:delete();
	break;
	case 3:display();
	break;
	case 4:printf("exit");
}

}while(choice!=4);

}
void delete(){
if(rear==-1||front>rear){
printf("queue is empty");
}
else{
printf("element deleted");
front=front+1;
}
}

void insert(){
int new;
if(rear==n-1)
	printf("queue overflow\n");
else{
	if(front==-1)
	front=0;
	printf("Enter the element to be inserted:");
	scanf("%d",&new);
	rear=rear+1;
	arr[rear]=new;
}
}

void display(){
for(int i=front;i<=rear;i++){
printf("%d ",arr[i]);
}
}
