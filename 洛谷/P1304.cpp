#include<bits/stdc++.h>
using namespace std;
int prime[10001]={1,1,0};
int pd()
{
	for(int i=2;i<=10000;i++)
	{
		if(prime[i]==0)
		{
			for(int j=2*i;j<=10000;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	return 0;
}
int main()
{
	int n;
	pd();
	scanf("%d",&n);
	for(int i=4;i<n+2;i+=2)
	{
		for(int j=2;j<=i/2;j++)
		{
			if(prime[j]==0&&prime[i-j]==0)
			{
				printf("%d=%d+%d\n",i,j,i-j); 
				break;
			} 
		} 
	}
	return 0;
}

