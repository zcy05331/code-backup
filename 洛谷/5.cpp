#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,n,ans=0;
	scanf("%lld%lld",&x,&n);
	for(int i=1;i<=n;i++)
	{
		if(x<=5)ans+=250;
		x++;
		if(x>7)x=1;
	}
	printf("%lld",ans);
	return 0;
}

