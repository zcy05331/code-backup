#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
struct boat
{
	int t;
	int k;
	int x[300001]={};
	boat(){t=0;k=0;}
}a;
queue <boat> port;
stack <int> pas;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a.k,&a.t);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a.x[i]);
		}
		sort(a.x,a.x+a.k);
		port.push(a);
		while(a.t-port.front().t>86400)port.pop();
		
	}
	return 0;
}

