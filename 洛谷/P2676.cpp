#include<bits/stdc++.h>
using namespace std;
long long a[20001];
int main()
{
	long long n,b,s=0,ans=0;
	scanf("%lld%lld",&n,&b);
	for(int i=0; i<n; i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+0,a+n);
	for(int i=n-1; i>=0; i--)
	{
		s+=a[i];
		ans++;
		if(s>=b)
		{
			printf("%lld",ans);
			break;
		}
	}
	return 0;
}

