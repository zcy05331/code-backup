#include <bits/stdc++.h>

#define check(x, y) (x >= 0 && x < n && y >= 0 && y < m)

const int MaxN = 2010;
const int dx[] = {0, 1, -1, 0}, dy[] = {-1, 0, 0, 1};

struct p
{
    int x, y;
    int cntx, cnty;
};

int ans;

int n, m, x, y, limx, limy;

std::string s[MaxN];

int vis[MaxN][MaxN];

int disx[MaxN][MaxN], disy[MaxN][MaxN];

void bfs(int x, int y)
{
    memset(disx, 0x3f, sizeof(disx));
    memset(disy, 0x3f, sizeof(disy));
    std::queue<p> q;
    q.push((p){x, y, 0, 0});
    disx[x][y] = disy[x][y] = 0;
    while (!q.empty())
    {
        p tmp = q.front();
        q.pop();
        x = tmp.x, y = tmp.y;
        
        for (int i = 0; i <= 3; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (!check(nx, ny) || s[nx][ny] == '*')
                continue;
            int cntx = tmp.cntx + bool(dy[i] == -1), cnty = tmp.cnty + bool(dy[i] == 1);
            if (cntx < std::min(disx[nx][ny], limx + 1) || cnty < std::min(disy[nx][ny], limy + 1))
            {
                disx[nx][ny] = cntx;
                disy[nx][ny] = cnty;
                q.push((p){nx, ny, cntx, cnty});
                //printf("x = %d, y = %d, nx = %d, ny = %d, disx = %d, disy = %d, dy = %d\n", x + 1, y + 1, nx + 1, ny + 1, disx[x][y], disy[x][y], dy[i]);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d", &x, &y), --x, --y;
    scanf("%d%d", &limx, &limy);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];
    bfs(x, y);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (disx[i][j] <= limx && disy[i][j] <= limy)
                ++ans;
    printf("%d\n", ans);
    return 0;
}