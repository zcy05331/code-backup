#include <bits/stdc++.h>

#define R register
#define ll long long
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) (((a) + (b)) % mod)
#define check(ex, ey) ((ex > 0) && (ex <= n) && (ey > 0) && (ey <= m))

int n, m, cnt, col;
int a[310][310], vis[310][310], visit[100001];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

inline void bfs(int x, int y)
{
    std::queue<std::pair<int, int>> q;
    q.push(mp(x, y)), vis[x][y] = col;
    while (!q.empty())
    {
        std::pair<int, int> s = q.front();
        q.pop(), x = s.first, y = s.second;
        for (int i = 0; i < 4; i++)
        {
            int ex = x + dx[i], ey = y + dy[i];
            if (a[ex][ey] && !vis[ex][ey] && check(ex, ey))
                q.push(mp(ex, ey)), vis[ex][ey] = col;
            else if (a[ex][ey] && vis[ex][ey] != col && check(ex, ey))
            {
                if (!visit[vis[ex][ey]])
                    visit[vis[ex][ey]] = 1, --cnt;
                q.push(mp(ex, ey)), vis[ex][ey] = col;
            }
        }
    }
}
char ch[1000];
int main()
{
    scanf("%d%d", &n, &m);
    for (R int i = 1; i <= n; i++)
    {
        scanf("%s", ch);
        for (R int j = 1; j <= m; j++)
            a[i][j] = ch[j - 1] - '0';
    }
    for (R int i = 1; i <= n; ++i)
        for (R int j = 1; j <= m; ++j)
            if (a[i][j] && !vis[i][j])
                ++col, bfs(i, j), ++cnt;
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (R int i = x1; i <= x2; ++i)
            for (R int j = y1; j <= y2; ++j)
                a[i][j] = 1;print("x")
        ++col, bfs(x1, y1), ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}
