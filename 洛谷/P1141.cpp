#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int dx[4]= {0,1,0,-1},dy[4]= {1,0,-1,0};
int n,m;
int vis[1001][1001],a[1001][1001];
char s[1001][1001];
int x[100001],y[100001];
queue <pair<int,int>> q;
void init()
{
	memset(vis,0,sizeof(vis));
}
int search(int x,int y)
{
	pair<int,int>tmp;
	int ans=0;
	tmp=make_pair(x,y);
	q.push(tmp);
	vis[x][y]=1;
	while(!q.empty())
	{

		tmp=q.front();
		q.pop();
		ans++;
		int f=tmp.first,v=tmp.second;
		//printf("x=%d y=%d\n",f,v);
		for(int i=0; i<=3; i++)
		{
			int fir=f+dx[i],sec=v+dy[i];
			if(fir<=0||fir>n||sec<=0||sec>n)continue;
			if(a[f][v]==(!a[fir][sec])&&vis[fir][sec]==0)
			{
				vis[fir][sec]=1;
				tmp=make_pair(fir,sec);
				q.push(tmp);
			}
		}
	}
	return ans;
}
int main()
{

	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1; j<=n; j++)
		{
			a[i][j]=s[i][j]-'0';
		}
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1; i<=m; i++)
	{
		init();
		printf("%d\n",search(x[i],y[i]));
	}
	return 0;
}


