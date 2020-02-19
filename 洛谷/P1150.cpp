#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k,ans=0,m;
	scanf("%lld%lld",&n,&k);
	ans+=n;
	m=k;
	while(n>=k)
	{
		ans+=n/k;
		m=n/k;
		n%=k;
		n+=m;
	}
	printf("%d",ans);
	return 0;
}

