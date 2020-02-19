#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v,w;
	edge(int _u,int _v,int _w): u(_u),v(_v),w(_w) {}
	edge() {}
} e[200005];
int f[5005];
int getf(int x)
{
	if(f[x]==x)return x;
	else f[x]=getf(f[x]);
	return f[x];
}
bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)f[i]=i;
	for(int i=0; i<m; i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[i]=edge(x,y,z);
	}
	sort(e,e+m,cmp);
	int k=0,tot=0;
	for(int i=0; i<m; i++)
	{
		if(getf(e[i].u)!=getf(e[i].v))
		{
			f[getf(e[i].u)]=getf(e[i].v);
			tot+=e[i].w;
			k++;
		}
		if(k==n-1)break;

	}
	if(k!=n-1)printf("orz\n");
	else printf("%d\n",tot);
	return 0;
}


