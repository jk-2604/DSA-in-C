#include <stdio.h>

void heapSort(int arr[], int N);

void swap(int *x, int *y);
void heapify (int arr[], int N, int i);
void print_arr(int arr[], int N);
void swap (int *x, int *y){ // function to swap the elements 
    int t=*x;
    *x=*y;
    *y=t;
}
void heapify (int arr[], int N, int k){ //Conversion of a binary tree into a heap. 
    int l=k;
    int left= 2*k + 1;
    int right= 2*k + 2; 
    //Determine the largest value among the root, its left child, and its right child, then set the largest value as the new root. 
    if(left<N && arr[left]>arr[l]){ //condition defined to check if the left child is greater than the root. 
        l=left;
    } 
    
    if(right<N && arr[right]>arr[l]){ //Condition defined to check if the right child is greater than the root. 
        l=right;
    } 
    
    if(l!=k){
        swap( &arr[k], &arr[l] ); //the case when the root is not the largest. 
        heapify(arr, N, l); //Recursion defined
    }
}

void heapSort(int arr[], int N){ //function to implement hearpsort 
    int i;
    
    for(i=N/2 - 1;i>=0;i--){ //Construct a maximum heap, where elements are arranged in descending order property. 
        heapify(arr, N, i); //Call the heapify function. 
    }
    
    for(i=N-1;i>=0;i--){
        swap(&arr[0],&arr[i]); //calling the heapify function to set the root as the highest element
        heapify(arr, i, 0); 
    }
}

void print_arr(int arr[], int N){ //function to print the array 
    int j;
    for(j=0;j<N;j++){
        printf("%d ", arr[j]);
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
    heapSort(arr, size); //Calling the function to perform heapSort. 
    print_arr(arr, size); //Calling the function to print the final array. 
    return 0;
}

