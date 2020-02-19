#include <bits/stdc++.h>

const int MaxN = 2010;

int n, m, cnt, tim;
std::queue<int> q;
int vis[MaxN][MaxN], b[MaxN], ans[MaxN], ind[MaxN];
bool map[MaxN][MaxN], eq[MaxN][MaxN], map2[MaxN][MaxN];

inline void dfs(int x)
{
    b[x] = cnt;
    for (int i = 1; i <= 2000; i++)
        if (eq[x][i] && (!b[i]))
            dfs(i);
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
inline char getch()
{
    char C = getchar();
    while (C == ' ' or C == '\n')
        C = getchar();
    return C;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char T = getch();
            map[i][j + 1000] = (T == '<');
            map[j + 1000][i] = (T == '>');
            eq[i][j + 1000] = eq[j + 1000][i] = (T == '=');
        }
    }
    for (int i = 1; i <= n; i++)
        if (!b[i])
            ++cnt, dfs(i);
    for (int i = 1; i <= m; i++)
        if (!b[i + 1000])
            ++cnt, dfs(i + 1000);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((b[i] == b[j + 1000]) && (!eq[i][j + 1000]))
                return 0 * printf("No\n");
            if (vis[b[i]][b[j + 1000]] && map2[b[i]][b[j + 1000]] != map[i][j + 1000])
                return 0 * printf("No\n");
            map2[b[i]][b[j + 1000]] = map[i][j + 1000];
            map2[b[j + 1000]][b[i]] = map[j + 1000][i];
            vis[b[i]][b[j + 1000]] = vis[b[j + 1000]][b[i]] = 1;
        }
    }
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++)
            if (map2[i][j])
                ++ind[j];
    for (int i = 1; i <= cnt; i++)
        if (!ind[i])
            q.push(i);
    while (!q.empty())
    {
        ++tim;
        for (int i = q.size(); i--;)
        {
            int x = q.front();
            q.pop();
            ans[x] = tim;
            for (int j = 1; j <= cnt; j++)
                if (map2[x][j])
                {
                    --ind[j];
                    if (!ind[j])
                        q.push(j);
                }
        }
    }
    for (int i = 1; i <= cnt; i++)
        if (!ans[i])
            return 0 * printf("No");
    printf("Yes\n");
    for (register int i = 1; i <= n; ++i)
        printf("%d ", ans[b[i]]);
    printf("\n");
    for (register int i = 1; i <= m; ++i)
        printf("%d ", ans[b[i + 1000]]);
    printf("\n");
    return 0;
}
