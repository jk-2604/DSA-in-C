#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b)        //function defined  for swapping the two integers
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high)       //Partition function
{
    int i,j;
    int pivot=arr[low];                         //assigning the pivot elementto the first elemetn of the array
    i=low;
    j=high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)       //find the first element greater than the pivot
        {
            i++;
        }
        while(arr[j]>pivot && j>=low+1)         //finding the first element lesses than the pivot
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high);
void quickSort(int arr[],int low,int high)          //quick sort function
{
    if(low<high)
    {
        int partition_index=partition(arr,low,high); //partion function called to find the position for partition
        
        quickSort(arr,low,partition_index-1);       //sorting the first sub-array
        quickSort(arr,partition_index+1,high);      //sorting the second sub-array.
    }
}
int main(){
    int size = 0;
    scanf("%d",&size);  //Enter size of array
    int arr[size];
    int temp;
    for(unsigned int i = 0; i<size;i++){    // take inputs in the array
        scanf("%d",&temp);
        arr[i] = temp;
    }
    quickSort(arr,0,size-1);                //sorting the array using quicksort
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
