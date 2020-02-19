#include<bits/stdc++.h>
using namespace std;
int see[300001],a[300001];
stack<int>s;
int main()
{
	long long ans=0,n;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n-1;i>=0;i--)
	{
		   while (!s.empty() && a[s.top()] < a[i])
		{
			see[i] += see[s.top()] + 1;
			s.pop();
		}
		s.push(i);
		ans += see[i];
	}
	printf("%lld",ans);
	return 0;
}
