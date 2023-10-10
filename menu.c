#include<stdio.h>
#include<stdlib.h>
int choice,j,i=0,arr[50],b[10],s;
void insert();
void menu();
void delete();
void sort();
void search();
void display();
int main()
{

 printf("\nEnter size of array :");
 scanf("%d",&s);
 printf("\nEnter elements of array:");

 for(i=0;i<s;i++)

    scanf("%d",&arr[i]);

menu();
}
void menu()
{    
    printf("\n\t1. Insert");
    printf("\n\t2. Delete");
    printf("\n\t3. Sort");
    printf("\n\t4. Search");
    printf("\n\t5. display");
    printf("\n\t6. Exit");
    printf("\n\n\t Your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1: insert();
        break;
    case 2: delete();
    	break;
    case 3:sort();
    	break;
    case 4: search();
    	break;
    case 5: display();
    	break;
    case 6: exit(1);
  
   
    }
}
void search()
{       int ele,loc;

    printf("\n\n                       Array Searching\n");
    printf("                       ----------------\n");
    printf("\n\n\tEnter Element to be searched : ");
    scanf("%d",&ele);
    printf("Elements Found at : ");
    for(i=0;i<s;i++)
    {       if(ele==arr[i])
        printf("%d ",i+1);
    }
  
    menu();

}
void insert()
{
    int loc,ele;
 
    for(i=0;i<s;i++)
        printf("%d  ",arr[i]);
    printf("\n\n\tEnter location : ");
    scanf("%d",&loc);
    printf("Enter Element : ");
    scanf("%d", &ele);
    for(i=s;i>loc-1;i--)
        arr[i]=arr[i-1];
    arr[loc-1]=ele;
    printf("\n\n\tElement Inserted");
    printf("\n\n\tNew Array : ");
    s++;
    for(i=0;i<s;i++)
        printf("%d  ",arr[i]);
    
    menu();
}
void delete()
{   int loc;
    printf("\n\n\tNew Array : ");
    for(i=0;i<s;i++)
        printf("%d  ",arr[i]);
    printf("\n\n\tEnter location : ");
    scanf("%d",&loc);

    for(i=loc;i<s-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[s-1]=-1;
    printf("\n\n\tElement Deleted");
    printf("\n\n\tNew Array : ");
    s--;
    for(i=0;i<s;i++)
        printf("%d  ",arr[i]);

    menu();
}
void sort()
{
    printf("\n\n\tCurrent Array : ");
    for(i=0;i<s;i++)
        printf("%d  ",arr[i]);

  
    for(i=0;i<s;i++)
    {
        for(j=i+1;j<s;j++)
        if (arr[i]>arr[j])
        {         arr[i]=arr[i]+arr[j];
            arr[j]=arr[i]-arr[j];
            arr[i]=arr[i]-arr[j];
        }
     }
    printf("\n\n\tElements Sorted");
    printf("\n\n\tSorted Array : ");
    for(i=0;i<s;i++)
        printf("%d  ",arr[i]);

    menu();
}
void display(){
int i;
if(s==0){
	printf("no elements to display!");
	return;
}
else{
	printf("array elements are:");
	for(i=0;i<s;i++){
	printf("%d",arr[i]);
	}
}
menu();
}

