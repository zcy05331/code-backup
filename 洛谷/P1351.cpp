#include <bits/stdc++.h>

const int MaxN = 200010, mod = 10007;

struct edge
{
    int to, next;
};

int w[MaxN];
edge e[MaxN << 1];
int cnt, head[MaxN];

int add_edge(int u, int v)
{
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int main()
{
    int n;
    int pmax = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for(int i = 1; i <= n; i++)scanf("%d", &w[i]);
    for(int i = 1; i <= n; i++)
    {
        int curmax, cursum, cur;
        cur = head[i];
        curmax = cursum = w[e[cur].to];
        cur = e[cur].next;
        for(; cur; cur = e[cur].next)
        {
            ans = (ans + cursum * w[e[cur].to]);
            pmax = std::max(pmax, curmax * w[e[cur].to]);
            cursum = (cursum + w[e[cur].to]) % mod;
            curmax = std::max(curmax, w[e[cur].to]);
        }
    }
    printf("%d %d", pmax, (ans * 2) % mod);
    return 0;
}