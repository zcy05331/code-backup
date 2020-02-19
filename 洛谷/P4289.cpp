#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) ((a + b) % mod)
#define checkpos(i, j) (i > 0 && i < 5 && j > 0 && j < 5)

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int ans, a[5][5], b[5][5], tmp[5][5];

inline int check()
{
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if (b[i][j] != tmp[i][j])
                return 0;
    return 1;
}

inline void dfs(int n, int x)
{
    if (check())
    {
        ans = n;
        return;
    }
    if (x > n)
        return;
    int cnt = 0;
    std::vector<std::pair<int, int>> X, Y;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (!tmp[i][j])
                continue;
            for (int k = 0; k <= 3; k++)
            {
                int ex = i + dx[k], ey = j + dy[k];
                if (!checkpos(ex, ey))
                    continue;
                if (tmp[ex][ey])
                    continue;
                X.push_back(mp(ex, ey)), Y.push_back(mp(i, j)), ++cnt;
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        std::swap(tmp[X[i].first][X[i].second], tmp[Y[i].first][Y[i].second]);
        dfs(n, x + 1);
        std::swap(tmp[X[i].first][X[i].second], tmp[Y[i].first][Y[i].second]);
    }
}

inline void set()
{
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            tmp[i][j] = a[i][j];
}

int main()
{
    std::string s;
    for (int i = 1; i <= 4; i++)
    {
        std::cin >> s;
        for (int j = 1; j <= 4; j++)
            a[i][j] = s[j - 1] - '0';
    }
    for (int i = 1; i <= 4; i++)
    {
        std::cin >> s;
        for (int j = 1; j <= 4; j++)
            b[i][j] = s[j - 1] - '0';
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            if (a[i][j] == b[i][j])
                a[i][j] = b[i][j] = 0;
    }
    if (check())
        return 0 * printf("0");
    for (int i = 0; i <= 11; i++)
    {
        set();
        dfs(i, 1);
        if (ans)
            return 0 * printf("%d\n", ans);
    }
    return 0;
}
