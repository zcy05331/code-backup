#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int b,p,k;
	long long ans=1;
	scanf("%d%d%d",&b,&p,&k);
	int bb=b,pp=p;
	while(p>=1)
	{
		if(p%2==1)
		{
			ans*=b;
			ans%=k;
			--p;
		}
		b=b*b%k;
		p/=2;
		ans%=k;
	}
	printf("%d^%d mod %d=%d",bb,pp,k,ans%k);
	return 0;
}

