#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int a[51];
int main()
{
	int p=0,m=0,c=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)scanf("%d",&a[i]);
	scanf("%d%d",&l,&r);
	for(int i=0; i<n; i++)
	{
		c+=a[i];
		if(a[i]<l)
		{
			p+=(l-a[i]);
		}
		else if(a[i]>r)
		{
			m+=(a[i]-r);
		}
	}
	if(c<n*l||c>n*r)printf("-1");
	else printf("%d",max(p,m));
	return 0;
}

