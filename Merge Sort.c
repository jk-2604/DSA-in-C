#include<stdio.h>
void sel_sort(int arr[],int size)  //function defined for selection sort
{
    int temp;
    int n=size;
    for(int i=0;i<n-1;i++)          //loop to iterate through (n-1) elements of the array
    {
        int min=i;
        for(int j=(i+1);j<n;j++)
        {
            if(arr[j]<arr[min])     //finding the minimun element in the unsorted array.
            {
                min=j;
            }
        }
        if(i!=min)                  //condition to check whether the ith element is already at its position.
        {
            temp=arr[i];            // swapping the ith element with the smallest element in the unsorted array.
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}
int main()
{
    int a[5]={5,3,4,2,1};           //training example
    sel_sort(a,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
