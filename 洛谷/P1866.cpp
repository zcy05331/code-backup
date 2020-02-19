#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int a[51];
int main()
{
	long long n,ans=1;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]) ;
	}
	sort(a+0,a+n);
	for(int i=0;i<n;i++)
	{
		ans=ans*(a[i]-i)%mod;
	}       
	printf("%lld",ans);
	return 0;
}

