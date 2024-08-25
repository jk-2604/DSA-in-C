#include <stdio.h>

int main(void)
{
    int nums[100], n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &nums[i]);
	}
    int i=0;
    while(nums[i]<=nums[i+1])
    {
        i++;
    }
    if((i==0) || ((i+1)==n))
    {
        printf("%d",0);
    }
    else
    {
    printf("%d",i+1);
    }
    return 0;
}
