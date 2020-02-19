#include<bits/stdc++.h>
using namespace std;
int a[10]={};
int main()
{
	long long n,m,tmp=0;
	scanf("%lld%lld",&m,&n);
	for(long long i=m;i<=n;i++)
	{
		tmp=i;
		while(tmp)
		{
			a[tmp%10]++;
			tmp/=10;
		}
	}
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

