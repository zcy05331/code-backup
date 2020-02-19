#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define check(i, j) (i > 0 && i <= (n + 1) && j > 0 && j <= (m + 1))

const int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, -1, 1};
const int ax[] = {0, 0, -1, -1}, ay[] = {0, -1, -1, 0};

int n, m;
int a[600][600], dis[600][600], vis[600][600];

struct node
{
    int x, y, cost;
};

inline void bfs()
{
    std::deque<node> dq;
    dq.push_back(node{1, 1, 0});
    int cnt = 0;
    while (!dq.empty())
    {
        node tmp = dq.front();
        ++cnt;
        int x = tmp.x, y = tmp.y, cost = tmp.cost;

        if ((dis[x][y] != -1 && dis[x][y] > cost) || dis[x][y] == -1)
            dis[x][y] = cost, vis[x][y] = cnt;
        //printf("%d %d %d %d\n", cnt, x, y, cost);
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int ex = x + dx[i], ey = y + dy[i], s = (i % 2) ? 1 : 2, c = 0;
            if (!check(ex, ey))
                continue;
            if (dis[ex][ey] != -1)
                continue;
            if (s != a[x + ax[i]][y + ay[i]])
                c = 1;
            if (c)
                dq.push_back((node){ex, ey, cost + 1});
            else
                dq.push_front((node){ex, ey, cost});
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        std::string s;
        memset(dis, -1, sizeof(dis));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> s;
            for (int j = 1; j <= m; j++)
                a[i][j] = (s[j - 1] == '/') ? 1 : 2;
        }
        bfs();
        // for (int i = 1; i <= n + 1; i++)
        // {
        //     for (int j = 1; j <= m + 1; j++)
        //         printf("%d ", dis[i][j]);
        //     puts("");
        // }
        if (dis[n + 1][m + 1] != -1)
            printf("%d\n", dis[n + 1][m + 1]);
        else
            printf("NO SOLUTION\n");
    }
    return 0;
}
