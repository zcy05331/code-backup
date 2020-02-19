#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define check(i, j) (i > 0 && i <= n && j > 0 && j <= n)

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int n, cnt, ans;
int a[10][10], vis[10], used[10], colored[10][10];

inline int f()
{
    int ret = 0;
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (colored[i][j] != 1 && !used[a[i][j]])
                used[a[i][j]] = 1, ++ret;
    return ret;
}

inline void change(int x, int y, int c)
{
    colored[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ex = x + dx[i], ey = y + dy[i];
        if (!check(ex, ey))
            continue;
        if (colored[ex][ey])
            continue;
        if (a[ex][ey] != c)
            colored[ex][ey] = 2;
        else
            change(ex, ey, c);
    }
}

inline void dfs(int lim, int dep, int last)
{
    if (ans)
        return;
    if (f() == 0)
    {
        ans = 1;
        return;
    }
    if (dep + f() > lim)
        return;
    for (int col = 0; col <= 5; col++)
    {
        if (col == last || !vis[col])
            continue;
        int tmp[10][10], flag = 0;
        memcpy(tmp, colored, sizeof(colored));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] == col && colored[i][j] == 2)
                    change(i, j, col), flag = 1;
        if (!flag)
            continue;
        dfs(lim, dep + 1, col);
        memcpy(colored, tmp, sizeof(tmp));
    }
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(colored, 0, sizeof(colored));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &a[i][j]);
                vis[a[i][j]]++;
                if (vis[a[i][j]] == 1)
                    ++cnt;
            }
        }
        if (cnt == 1)
        {
            printf("0\n");
            continue;
        }
        change(1, 1, a[1][1]);
        for (int i = f();; i++)
        {
            dfs(i, 0, 10);
            if (ans)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
