#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define check(i, j) (i > 0 && i < 6 && j > 0 && j < 6)

const int goal[7][7] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1},
    {0, 0, 0, 2, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0}};
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int a[10][10], tmp[10][10], ans = 0, sx, sy;

inline int f()
{
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (goal[i][j] != a[i][j])
                ++cnt;
    return cnt;
}

inline void dfs(int n, int dep, int x, int y)
{
    if (dep == n)
    {
        if (!f())
            ans = 1;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int ex = x + dx[i], ey = y + dy[i];
        if (!check(ex, ey))
            continue;
        std::swap(a[x][y], a[ex][ey]);
        if (dep + f() <= n)
            dfs(n, dep + 1, ex, ey);
        std::swap(a[x][y], a[ex][ey]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        std::string s;
        ans = 0, sx = 0, sy = 0;
        for (int i = 1; i <= 5; i++)
        {
            std::cin >> s;
            for (int j = 0; j < 5; j++)
            {
                if (s[j] == '*')
                    a[i][j + 1] = 2, sx = i, sy = j + 1;
                else
                    a[i][j + 1] = s[j] - '0';
            }
        }
        if (!f())
        {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= 15; i++)
        {
            dfs(i, 0, sx, sy);
            if (ans)
            {
                printf("%d\n", i);
                goto A;
            }
        }
        printf("-1\n");
    A:;
    }
    return 0;
}
