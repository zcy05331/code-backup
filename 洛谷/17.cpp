#include<bits/stdc++.h>
using namespace std;
long long a[100006]={};
int main()
{
	int n;
	scanf("%d",&n);
	for(register int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+0,a+n);
	for(register int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

