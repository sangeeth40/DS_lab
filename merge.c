#include<stdio.h>
int main(){
int  arr1[50],num1,arr2[50],num2,arr3[100];
printf("Enter the size of the first array: ");
scanf("%d",&num1);
printf("Enter the elements of the array: ");
for(int i=0;i<num1;i++){
	scanf("%d",&arr1[i]);
}
for(int i=0;i<num1;i++)
    {
        for(int j=i+1;j<num1;j++)
        if (arr1[i]>arr1[j])
        {         arr1[i]=arr1[i]+arr1[j];
            arr1[j]=arr1[i]-arr1[j];
            arr1[i]=arr1[i]-arr1[j];
        }
     }
printf("Enter the size of the second array: ");
scanf("%d",&num2);
printf("Enter the elements of the array: ");
for(int i=0;i<num2;i++){
	scanf("%d",&arr2[i]);
}
for(int i=0;i<num2;i++)
    {
        for(int j=i+1;j<num2;j++)
        if (arr2[i]>arr2[j])
        {         arr2[i]=arr2[i]+arr2[j];
            arr2[j]=arr2[i]-arr2[j];
            arr2[i]=arr2[i]-arr2[j];
        }
     }
for(int i=0;i<num1+num2;i++){
	if(i<num1){
	arr3[i]=arr1[i];
	}
	else{
	arr3[i]=arr2[i-num1];
	}

}
for(int i=0;i<num2+num1;i++)
    {
        for(int j=i+1;j<num2+num1;j++)
        if (arr3[i]>arr3[j])
        {         arr3[i]=arr3[i]+arr3[j];
            arr3[j]=arr3[i]-arr3[j];
            arr3[i]=arr3[i]-arr3[j];
        }
     }

printf("merged array");
for(int i=0;i<num1+num2;i++){
	printf("\n%d",arr3[i]);
}

}
