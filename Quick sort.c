#include<stdio.h>
void bubble_sort(int arr[],int size)        //function defined for bubble sort
{
    int n=size;
    int temp;
    for(int k=0;k<n-1;k++)                  
    {
        int flag=0;                         //flag initiated to check if all the elements after the ith iteration are sorted 
        for(int i=0;i<n-1-k;i++)
        {
            if(arr[i]>arr[i+1])             //adjacent elements swapped if not in order
            {
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
                flag++;
            }
        }
        if(flag==0)                         //if in the ith iteration no elements are swapped then the list is sorted, hence break
        {
            break;
        }
    }
}
void main()
{
    int a[5]={5,-1,3,6,1};                  //training example
    bubble_sort(a,5);                       
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);                 //printing the sorted array after bubble sort
    }
}
