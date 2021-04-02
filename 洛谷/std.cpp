#include "swap.h"

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct BCJ
{
    int fa[500000];
    void init(int n)
    {
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    int fnd(int x) { return x == fa[x] ? x : fa[x] = fnd(fa[x]); }
} B;

struct e
{
    int u, v, w;
    e(int uu = 0, int vv = 0, int ww = 0) : u(uu), v(vv), w(ww) {}
};
vector<e> ed;
bool operator<(e a, e b) { return a.w < b.w; }

bool conn[500000];
int st[500000], en[500000], rt[500000];
vector<int> pnt[500000];

vector<int> tr[500000];

int fa[500000][20], dep[500000];

void dfs(int u, int f)
{
    fa[u][0] = f;
    for (int i = 1; i < 20; i++)
        fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1];
    rt[u] = f == -1 ? u : rt[f], dep[u] = f == -1 ? 1 : dep[f] + 1;
    for (int i = 0; i < tr[u].size(); i++)
        dfs(tr[u][i], u);
}

int LCA(int x, int y)
{
    if (rt[x] != rt[y]) return -1;
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--)
    {
        if (fa[x][i] != -1 && dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}
int n, m;
void init(int N, int M, vector<int> U, vector<int> V, vector<int> W)
{
    n = N, m = M;
    for (int i = 0; i < M; i++)
        ed.push_back(e(U[i], V[i], W[i]));
    sort(ed.begin(), ed.end());
    B.init(N);
    for (int i = 0; i < N; i++)
        st[i] = en[i] = rt[i] = i, pnt[i].push_back(i);
    for (int i = 0; i < M; i++)
    {
        int u = ed[i].u, v = ed[i].v, fu = B.fnd(u), fv = B.fnd(v);
        if (pnt[fu].size() < pnt[fv].size())
        {
            swap(u, v), swap(fu, fv);
        }
        if (fu == fv)
        {
            if (!conn[fu])
            {
                conn[fu] = 1;
                for (int j = 0; j < pnt[fu].size(); j++)
                    tr[i + N].push_back(pnt[fu][j]);
                rt[fu] = i + N;
            }
        }
        else
        {
            if (conn[fu] || conn[fv])
            {
                if (conn[fu])
                    tr[i + N].push_back(rt[fu]);
                else
                    for (int j = 0; j < pnt[fu].size(); j++)
                        tr[i + N].push_back(pnt[fu][j]);
                if (conn[fv])
                    tr[i + N].push_back(rt[fv]);
                else
                    for (int j = 0; j < pnt[fv].size(); j++)
                        tr[i + N].push_back(pnt[fv][j]);
                conn[fu] = 1, rt[fu] = i + N;
                B.fa[fv] = fu;
            }
            else
            {
                if ((u == st[fu] || u == en[fu]) && (v == st[fv] || v == en[fv]))
                {
                    st[fu] = u ^ st[fu] ^ en[fu];
                    en[fu] = v ^ st[fv] ^ en[fv];
                    for (int j = 0; j < pnt[fv].size(); j++)
                        pnt[fu].push_back(pnt[fv][j]);
                    B.fa[fv] = fu;
                }
                else
                {
                    conn[fu] = 1;
                    for (int j = 0; j < pnt[fu].size(); j++)
                        tr[i + N].push_back(pnt[fu][j]);
                    for (int j = 0; j < pnt[fv].size(); j++)
                        tr[i + N].push_back(pnt[fv][j]);
                    B.fa[fv] = fu;
                    rt[fu] = i + N;
                }
            }
        }
    }
    /*for(int i=0;i<N+M;i++)
	{
		printf("%d: ",i);
		for(int j=0;j<tr[i].size();j++)printf("%d ",tr[i][j]);puts("");
	}*/
    for (int i = N + M - 1; i >= 0; i--)
    {
        if (!dep[i]) dfs(i, -1);
    }
    //for(int i=0;i<N+M;i++){printf("%d\n",dep[i]);for(int j=0;j<4;j++)printf("%d ",fa[i][j]);puts("");}
}

int getMinimumFuelCapacity(int X, int Y)
{

    int u = LCA(X, Y);
    if (u == -1) return -1;
    return ed[u - n].w;
}