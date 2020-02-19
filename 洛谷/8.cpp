#include<bits/stdc++.h>
using namespace std;
int a[10000]={};
int beg=0,en=0;
int main()
{
	int m,l;
	scanf("%d%d",&l,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&beg,&en);
		for(int j=beg;j<=en;j++)
		{
			if(a[j]==0)
			{
				l--;
				a[j]++;
			}
		}
	}
	printf("%d",l+1);
	return 0;
}

