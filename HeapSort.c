#include<stdio.h>

void merge(int arr[],int first, int mid,int last)  //function merge defined to merge the two sub-lists
{
    int i,j,k;
    int n1=mid-first+1;                 //parameters for dividing the first list into length n1
    int n2=last-mid;                    //parameter for dividing the second lisrinto length n2
    
    int temp1[n1];                      //creating temp first sub list
    int temp2[n2];                      //creating temp second sub list
    
    for(int i=0;i<n1;i++)               //feeding in data int temp1
    {
        temp1[i]=arr[first+i];
    }
    for(int j=0;j<n2;j++)               //feeding in data in temp2
    {
        temp2[j]=arr[mid + 1 + j];
    }
    i=0;
    j=0;
    k=first;
    while(i<n1 && j<n2)                 //merging in ascending order
    {
        if(temp1[i]<=temp2[j])
        {
            arr[k]=temp1[i];
            ++i;
        }
        else
        {
            arr[k]=temp2[j];
            ++j;
        }
        ++k;
    }
    while(i<n1)                     //filling in the rest of the data
    {
        arr[k]=temp1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=temp2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int first, int last)
{
    if(first<last)
    {
        int mid=first+(last-first)/2;
        
        merge_sort(arr,first,mid);
        merge_sort(arr,mid+1,last);
        
        merge(arr,first,mid,last);
    }
}

int main()
{
    int a[7]={12,2,14,4,3,45,32};
    merge_sort(a,0,6);
    for(int i=0;i<6;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}