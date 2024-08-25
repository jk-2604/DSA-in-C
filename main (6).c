#include <stdio.h> 

int main() 
{ 
    int price[100], n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &price[i]);
	}
	if(n<=1)
	{
	    return 0;
	}
	int minp=price[0];
	int max=0;
	for(int i=1;i<n;i++)
	{
	    if(price[i]<minp)
	    {
	        minp=price[i];
	    }
	    else if(price[i]-minp>0)
	    {
	        max+=price[i]-minp;
	        minp=price[i+1];
	    }
	}
	printf("%d",max);
	return 0; 
}
