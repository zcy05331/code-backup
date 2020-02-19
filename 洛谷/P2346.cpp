#include <bits/stdc++.h>

#define R register
#define ll long long
#define mp(i, j) std::make_pair(i, j)
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define checkpos(i, j) (i > 0 && i < 5 && j > 0 && j < 5)

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

char ch[5][5];
int a[5][5], tmp[5][5], ans = 998244353;

inline int check()
{
    for (int i = 1; i <= 4; i++)
    {
        int flag = 0;
        for (int j = 1; j <= 4; j++)
            if (tmp[i][j] == tmp[i][1])
                flag++;
        if (flag == 4)
            return 1;
    }
    for (int i = 1; i <= 4; i++)
    {
        int flag = 0;
        for (int j = 1; j <= 4; j++)
            if (tmp[j][i] == tmp[1][i])
                ++flag;
        if (flag == 4)
            return 1;
    }
    int flag = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (tmp[i][i] == tmp[1][1])
            flag++;
    }
    if (flag == 4)
        return 1;
    flag = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (tmp[i][5 - i] == tmp[1][4])
            flag++;
    }
    if (flag == 4)
        return 1;
    return 0;
}

inline void print()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            printf("%d", tmp[i][j]);
        puts("");
    }
    puts("");
}

inline void dfs(int n, int x, int s)
{
    if (check())
    {
        ans = cmin(n, ans);
        return;
    }
    if (x > n)
        return;
    int cnt = 0;
    std::vector<std::pair<int, int>> X, Y;
    X.clear(), Y.clear();
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (tmp[i][j] == 0)
            {
                for (int k = 0; k <= 3; k++)
                {
                    int ex = i + dx[k], ey = j + dy[k];
                    if (!checkpos(ex, ey))
                        continue;
                    X.push_back(mp(ex, ey)), Y.push_back(mp(i, j)), ++cnt;
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        if (tmp[X[i].first][X[i].second] != s)
            continue;
        std::swap(tmp[X[i].first][X[i].second], tmp[Y[i].first][Y[i].second]);
        dfs(n, x + 1, (s == 1) ? 2 : 1);
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
    for (int i = 1; i <= 4; i++)
    {
        scanf("%s", ch[i] + 1);
        for (int j = 1; j <= 4; j++)
        {
            if (ch[i][j] == 'B')
                a[i][j] = 2;

            else if (ch[i][j] == 'W')
                a[i][j] = 1;
        }
    }
    for (int i = 1; i <= 15; i++)
    {
        set();
        dfs(i, 1, 1);
        if (ans != 998244353)
            return 0 * printf("%d\n", ans);
        set();
        dfs(i, 1, 2);
        if (ans != 998244353)
            return 0 * printf("%d\n", ans);
    }
    printf("%d\n", ans);
    return 0;
}
