#include <bits/stdc++.h>
#define mp(i, j) std::make_pair(i, j)
const int MaxN = 3e5 + 10;

int n, cnt, top;
std::pair<int, int> ans[MaxN * 5];
int sta[MaxN], p[MaxN], id[MaxN], vis[MaxN];

inline void dfs(int u)
{
    vis[u] = 1, sta[++top] = u;
    if (vis[id[u]])
        return;
    else
        dfs(id[u]);
}

inline void change(int u, int v)
{
    if (u > v)
        std::swap(u, v);
    if (2 * abs(u - v) >= n)
        ans[++cnt] = mp(u, v);
    else
    {
        if (2 * (u - 1) >= n)
        {
            ans[++cnt] = mp(1, u);
            ans[++cnt] = mp(1, v);
            ans[++cnt] = mp(1, u);
        }
        else if (2 * (n - v) >= n)
        {
            ans[++cnt] = mp(v, n);
            ans[++cnt] = mp(u, n);
            ans[++cnt] = mp(v, n);
        }
        else
        {
            ans[++cnt] = mp(1, v);
            ans[++cnt] = mp(1, n);
            ans[++cnt] = mp(u, n);
            ans[++cnt] = mp(1, n);
            ans[++cnt] = mp(1, v);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]), id[p[i]] = i;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            top = 0, dfs(i);
            if (top == 1)
                continue;
            for (int j = 1; j < top; ++j)
                change(sta[j], sta[j + 1]);
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
