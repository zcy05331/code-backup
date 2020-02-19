#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,n,ans=1;
	scanf("%d%d",&x,&n);
	for(int i=0;i<n;i++)
	{
		ans+=ans*x;
	} 
	printf("%lld",ans);
	return 0;
}

