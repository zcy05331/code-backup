#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

const int maxn=200010;
int n,m,q,cnt;
struct edge{int u,v,dis;}rem[maxn];
struct node{int v,nxt;}E[maxn];
int head[maxn],tot;
int ff[maxn],val[maxn];
int fa[maxn],top[maxn],vis[maxn];
int dep[maxn],son[maxn],size[maxn];
bool cmp(edge a,edge b){return a.dis<b.dis;}

void add(int u,int v)
{
    E[++tot].nxt=head[u];
    E[tot].v=v;
    head[u]=tot;
}

int find(int x)
{
    if(x==ff[x])return x;
    else return ff[x]=find(ff[x]);
}

void dfs1(int u,int pa)
{
    size[u]=1; vis[u]=1;
    for(int i=head[u];i;i=E[i].nxt)
    {
        int v=E[i].v;
        if(v==pa) continue;
        dep[v]=dep[u]+1; fa[v]=u;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]])son[u]=v;
    }
}

void dfs2(int u,int tp)
{
    top[u]=tp;
    if(son[u]) dfs2(son[u],tp);
    for(int i=head[u];i;i=E[i].nxt)
    {
        int v=E[i].v;
        if(v==son[u]||v==fa[u]) continue;
        dfs2(v,v);
    }
}

void kruskal()
{
    for(int i=1;i<=n;++i)ff[i]=i;
    std::sort(rem+1,rem+1+m,cmp);
    for(int i=1;i<=m;++i)
    {
        int fu=find(rem[i].u),fv=find(rem[i].v);
        if(fu!=fv)
        {
            val[++cnt]=rem[i].dis;
            ff[cnt]=ff[fu]=ff[fv]=cnt;
            add(fu,cnt); add(cnt,fu);
            add(fv,cnt); add(cnt,fv);
        }
    }
    dfs1(cnt,0); dfs2(cnt,cnt);
}

int LCA(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]>dep[top[v]]) u=fa[top[u]];
        else v=fa[top[v]];
    }
    if(dep[u]<dep[v])return u;
    else return v;
}

int main() 
{
    n=read();m=read();q=read();cnt=n;
    for(int i=1;i<=m;++i)
    rem[i].u=read(),rem[i].v=read(),rem[i].dis=read();

    kruskal();
    while(q--)
    {
        int u=read(),v=read();
        printf("%d\n",val[LCA(u,v)]);
    }
    return 0;
}