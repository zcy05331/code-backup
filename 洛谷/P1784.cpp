#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int a[10][10], ans;
std::bitset<20> r[20], c[20], grid[20];

inline int g(int x, int y) { return ((x - 1) / 3) * 3 + ((y - 1) / 3) + 1; }

inline void print()
{
    ans = 1;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
            printf("%d ", a[i][j]);
        puts("");
    }
}

inline void dfs(int x, int y)
{
    if (ans == 1)
        return;
    if (x == 10)
        return (void)print();
    if (y == 10)
        return (void)dfs(x + 1, 1);
    if (a[x][y])
        return (void)dfs(x, y + 1);
    std::bitset<20> tmp = r[x] | c[y] | grid[g(x, y)];
    for (int i = 1; i <= 9; i++)
    {
        if (!tmp[i])
        {
            a[x][y] = i;
            r[x][i] = c[y][i] = grid[g(x, y)][i] = 1;
            dfs(x, y + 1);
            a[x][y] = 0;
            r[x][i] = c[y][i] = grid[g(x, y)][i] = 0;
        }
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
                r[i][a[i][j]] = c[j][a[i][j]] = grid[g(i, j)][a[i][j]] = 1;
        }
    }
    dfs(1, 1);
    return 0;
}
