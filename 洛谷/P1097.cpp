#include<bits/stdc++.h>
using namespace std;
long long a[200005]={};
long long cmp(const long long& a,const long long &b)
{
	return a<b;
}
int main()
{
	int n;
	long long tmp,num=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	for(int i=0; i<n; i++)
	{
		if(num==0)
		{
			tmp=a[i];
			printf("%d ",tmp);
		}
		num++;
		if(a[i+1]!=tmp)
		{
			printf("%d\n",num);
			num=0;
		}
	}
	return 0;
}

