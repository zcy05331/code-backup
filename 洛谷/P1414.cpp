#include<bits/stdc++.h>
using namespace std;
int a[10001],b[1000001];
void doit(int x)
{
	for(int i=1;i<=int(sqrt(x)+0.5);i++)
	{
		if(x%i==0)
		{
			b[i]++;
			b[x/i]++;
			if(i*i==x)
			{
				b[i]--;
			}
		}
	}
} 
int main()
{
	int n,inf=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		doit(a[i]);
		inf=(inf>=a[i])?inf:a[i];
	}
	int p=inf; 
	for(int i=1;i<=n;i++)
	{
		while (b[p] < i) p--;
        printf("%d\n",p);
	}
	return 0;
}

