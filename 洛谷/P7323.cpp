#include <bits/stdc++.h>

#define R register
#define ll long long
#define pair std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)
#define It std::unordered_map<int, int>::iterator

const int MaxN = 6e5 + 10;

std::queue< pair > q;
std::unordered_map<int, int> b[MaxN];

ll ans, siz[MaxN];
int n, m, k, fa[MaxN];

int getf(int x)
{
    if(x != fa[x])
        fa[x] = getf(fa[x]);
    return fa[x];
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{   
    n = read(), m = read(), k = read();
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    while(m--)
    {
        int u = read(), v = read(), w = read();
        if(b[v][w]) q.push(mp(u, b[v][w]));
        else b[v][w] = u;
    }
    while(!q.empty())
    {
        int u = getf(q.front().first);
        int v = getf(q.front().second);
        if(b[u].size() > b[v].size()) std::swap(u, v);
        q.pop(); if(u == v) continue; fa[u] = v;
        for(It it = b[u].begin(); it != b[u].end(); it++)
        {
            int op = it->first;
            if(b[v][op]) q.push(mp(it->second, b[v][op]));
            else b[v][op] = it->second;
        }
        b[u].clear();
    }
    for(int i = 1; i <= n; i++)
        siz[getf(i)]++;
    for(int i = 1; i <= n; i++)
        ans += siz[i] * (siz[i] - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}
