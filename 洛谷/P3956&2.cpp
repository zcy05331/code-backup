#include<bits/stdc++.h>
#include<queue>
using namespace std;
int dx[]={-1,+1,0,0},dy[]={0,0,-1,+1};
int a[101][101]={},cost[101][101]={};
struct block
{
	int x,y;
	int cost;
	int color;
	int can;
}tmp;
int m,n;
queue<block>que;
void expand(int x,int y)
{
	int v;
	if(x<0||x>=m||y<0||y>=m)return;
	if(a[x][y]!=0)
	{
		v=(tmp.color==a[x][y])?tmp.cost:tmp.cost+1;
		if(v<cost[x][y])
		{
			cost[x][y]=v;
			que.push((block){x,y,v,a[x][y],1});
		}
		return;
	}
	if(tmp.can==0)return;
	v=tmp.cost+2;
	if(v<cost[x][y])
	{
		cost[x][y]=v;
		que.push((block){x,y,v,tmp.color,0});
	}
} 
int main()
{
	memset(cost,127,sizeof(cost));
	int x,y,c;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		a[x-1][y-1]=c+1;
	}
	que.push((block){0,0,0,a[0][0],1});
	cost[0][0]=0;
	while(!que.empty())
	{
		tmp=que.front();
		que.pop();
		expand(tmp.x-1,tmp.y);
		expand(tmp.x+1,tmp.y);
		expand(tmp.x,tmp.y-1);
		expand(tmp.x,tmp.y+1);
	}
	if(cost[m-1][m-1]<20000) printf("%d",cost[m-1][m-1]);
	else printf("-1");
	return 0;
}

