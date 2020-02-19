#include<bits/stdc++.h>
using namespace std;
int a[1001][1001]= {},sum[1001]= {},sum2[1001],x[10001],y[10001];
int main()
{
	int n,xy=0,maxx=0;
	int tmp;
	scanf("%d",&n);
	tmp=n*n;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j])tmp--;
			else
			{
				x[xy]=i;
				y[xy]=j;
				xy++;
			}
		}

	}
	if(tmp==0)
	{
		printf("Bad Game!");
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			sum[i]+=a[i][j];
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			sum2[i]+=a[j][i];
		}
	}
	for(int i=0; i<xy; i++)
	{
		tmp=sum[x[i]]+sum2[y[i]];
		if(tmp>maxx)maxx=tmp;
	}
	printf("%d",maxx);
	return 0;
}

