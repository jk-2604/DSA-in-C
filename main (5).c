#include <stdio.h>

// Driver code
int main()
{
    int vec[100], n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &vec[i]);
	} 
	int *num,*num2;
    num=(int *) malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++)
    {
        num[i]=i;
    }
    num2=(int *) malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++)
    {
        num2[i]=0;
    }
    for(int j=0;j<=n;j++)
    {
        num2[vec[j]]=vec[j];
    }
    for(int i=0;i<=n;i++)
    {
        num[i]=num[i]-num2[i];
    }
    for(int j=0;j<=n;j++)
    {
        if(num[j]!=0)
        {
            printf("%d ",num[j]);
        }
    }
    
    
	return 0;
}

