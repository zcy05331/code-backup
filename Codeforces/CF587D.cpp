#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct node
{
    int u, v, c, t;
};

node t[MaxN];
int n, m, cnt, dfscnt, colcnt;
int col[MaxN], dfn[MaxN], low[MaxN], ins[MaxN];
std::vector<int> st, ans, tmp, e[MaxN], g[MaxN];

int cmp(int a, int b) { return t[a].c < t[b].c; }

void roolback(int mid)
{
    for (int i = 1; i <= m; i++)
        if (t[i].t > mid)
            g[i].pop_back();
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

void add_edge(int type)
{
    int Suf, Suf1;
    for (int i = 0; i < tmp.size(); i++)
    {
        int x = tmp[i], x1 = x + m;
        int suf = ++cnt, suf1 = ++cnt;
        if (!type)
        {
            g[x].push_back(suf), g[suf1].push_back(x1);
            if (i)
            {
                g[Suf].push_back(x1), g[x].push_back(Suf1);
                g[Suf].push_back(suf), g[suf1].push_back(Suf1);
            }
        }
        else
        {
            g[suf].push_back(x), g[x1].push_back(suf1);
            if (i)
            {
                g[x1].push_back(Suf), g[Suf1].push_back(x);
                g[suf].push_back(Suf), g[Suf1].push_back(suf1);
            }
        }
        Suf = suf, Suf1 = suf1;
    }
    tmp.clear();
}


void tarjan(int u)
{
    dfn[u] = low[u] = ++dfscnt;
    ins[u] = 1, st.push_back(u);
    for (auto v : g[u])
    {
        if (!dfn[v])
            tarjan(v), low[u] = std::min(low[u], low[v]);
        else if (ins[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int v;
        ++colcnt;
        do
        {
            v = st.back(), st.pop_back();
            col[v] = colcnt, ins[v] = 0;
        } while (u != v);
    }
}

int check(int mid)
{
    for (int i = 1; i <= m; i++)
        if (t[i].t > mid)
            g[i].push_back(i + m);
    for(int i = 1; i <= cnt; i++)
        dfn[i] = 0;
    colcnt = dfscnt = 0;
    for (int i = 1; i <= cnt; i++)
        if (!dfn[i]) tarjan(i);
    int flag = 1;
    for (int i = 1; i <= m; i++)
        if (col[i] == col[i + m])
            flag = 0;
    roolback(mid);
    return flag;
}

int main()
{
    int l = 0, r = 0;
    n = read(), m = read(), cnt = m << 1;
    for (int i = 1; i <= m; i++)
    {
        t[i].u = read(), t[i].v = read(), t[i].c = read(), t[i].t = read();
        e[t[i].u].push_back(i), e[t[i].v].push_back(i), r = std::max(r, t[i].t);
    }
    for (int i = 1; i <= n; i++)
    {
        std::sort(e[i].begin(), e[i].end(), cmp);
        tmp = e[i], add_edge(0);
        for (int j = 0; j < e[i].size(); j++)
        {
            int now = j;
            while ((now < e[i].size()) && (t[e[i][j]].c == t[e[i][now]].c))
                tmp.push_back(e[i][now]), ++now;
            add_edge(1), j = now - 1;
        }
    }
    // printf("%d\n", cnt);
    if (!check(r)) return 0 * puts("No");
    printf("Yes\n");
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    check(l);
    for (int i = 1; i <= m; i++)
        if (col[i] < col[i + m])
            ans.push_back(i);
    printf("%d %d\n", l, ans.size());
    for (auto i : ans)
        printf("%d ", i);
    return 0;
}