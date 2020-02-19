#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100001];
long long s[100001];
int check(int x)
{
	int now=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(now+a[i]>x)
		{
			now=a[i];
			cnt++;
		}
		else now+=a[i];
	}
	return cnt>=m;
}
int main()
{
	scanf("%d%d",&n,&m);
	long long l=0,r;
	for(int i=0; i<n; i++)
	{
		scanf("%lld",&a[i]);
		l=max(l,a[i]);
		r+=a[i];
	}
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}


