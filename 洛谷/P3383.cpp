#include<bits/stdc++.h>
using namespace std;
bool a[10000001]={}; 
int isprime(int n)
{
	a[0]=a[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==0)
		{
			for(int j=2*i;j<=n;j+=i)
			{
				a[j]=1;
			}
		}
	}
	return 0;
}
int main()
{
	int n,tmp,m;
	scanf("%d%d",&n,&m);
	isprime(n);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&tmp);
		if(a[tmp]==0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

