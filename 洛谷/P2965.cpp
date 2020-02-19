#include<bits/stdc++.h>
using namespace std;
int n,m,cost=0;
int head[20001];
int money[20001];
int main()
{
	int h=0,mx=0;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&head[i]);
	}
	for(int i=0; i<m; i++)
	{
		scanf("%d",&money[i]);
	}
	sort(head,head+n);
	sort(money,money+m);
	if(m<n)
	{
		printf("you died!");
		return 0;
	}
	while(h<n)
	{
		if(mx>=m)
		{
			printf("you died!");
			return 0;
		}
		if(money[mx]>=head[h])
		{
			cost+=money[mx];
			mx++;
			h++;
		}
		else
		{
			while(money[mx]<head[h])mx++;
		}
	}
	printf("%d",cost);
	return 0;
}

