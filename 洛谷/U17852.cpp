#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int inf=0x7ffffff;
int n,m,s;
struct edge
{
    int next;
    int to;
    int dis;
    int from;
} edge[500001]={};
int head[500001],dis[10001],vis[10001],cnt=0,u[100001],v[100001],d[100001];
inline int addedge(int v,int u,int d)
{
    cnt++;
    edge[cnt].dis=d;
    edge[cnt].to=u;
    edge[cnt].next=head[v];
    head[v]=cnt;
    edge[cnt].from=v;
}
inline int init()
{
    for(register int i=1; i<=n; i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
}
int main()
{
    register int x,y,ans=0;
    scanf("%d%d",&n,&m);
    s=1;
    for(register int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&d[i]);
        addedge(u[i],v[i],d[i]);
    }
    init();
    queue<int>que;
    que.push(s);
    dis[s]=0;
    vis[s]=1;
    while(!que.empty())
    {
        x=que.front();
        que.pop();
        vis[x]=0;
        for(register int i=head[x]; i; i=edge[i].next)
        {
            y=edge[i].to;
            if(dis[y]>dis[x]+edge[i].dis)
            {
                dis[y]=dis[x]+edge[i].dis;
                if(vis[y]==0)
                {
                    vis[y]=1;
                    que.push(y);
                }
            }
        }
    }
    for(register int i=1; i<=n; i++)
    {
        dis[i]=(i==s)?0:dis[i];
        //printf("%d ",dis[i]);
        ans+=dis[i];
    }
    memset(head,0,sizeof(head)) ;
    memset(edge,0,sizeof(edge));
    cnt=0;
    for(int i=1;i<=m;i++)
    {
		addedge(v[i],u[i],d[i]);
	}
	init();
    que.push(s);
    dis[s]=0;
    vis[s]=1;
    while(!que.empty())
    {
        x=que.front();
        que.pop();
        vis[x]=0;
        for(register int i=head[x]; i; i=edge[i].next)
        {
            y=edge[i].to;
            if(dis[y]>dis[x]+edge[i].dis)
            {
                dis[y]=dis[x]+edge[i].dis;
                if(vis[y]==0)
                {
                    vis[y]=1;
                    que.push(y);
                }
            }
        }
    }
    for(register int i=1; i<=n; i++)
    {
        dis[i]=(i==s)?0:dis[i];
        //printf("%d ",dis[i]);
        ans+=dis[i];
    }
    printf("%d",ans);
    return 0;
}

