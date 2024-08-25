#include <stdio.h>
int bs(int a[],int i, int j, int x)
{
    int mid;
    if(i==j)
    {
        if(a[i]==x){
            return i;
        }
        else{
            return -1;
        }
    }
    else{
        mid=(i+j)/2;
        if(a[mid]==x){
            return mid;
        }
        else{
            if(a[mid]>x){
                bs(a,i,mid-1,x);
            }
            else{
                bs(a,mid+1,j,x);
            }
        }
    }
}
int main(void)
{
    int nums[100], n, target;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &nums[i]);
	} 
    scanf("%d", &target);
    int j;
    j=bs(&nums[0],0,(n-1),target);
    while(nums[j-1]==target){
        j--;
    }
    printf("%d",j);
    return 0;
}

