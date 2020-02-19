#include <cstdio>
#include <cstring>
#include <cstdlib>
struct nodea
{
    int x, y, d, g, f;
} e[1000001];
struct nodeb
{
    int first, h;
} r[1000001];
int inf = 999999999, st = 1001, ed = 1002, n = 0;
int q[1000001], len = 0;
int min(int x, int y)
{
    return x < y ? x : y;
}
void ins(int x, int y, int d)
{
    len++;

    e[len].x = x;
    e[len].y = y;
    e[len].d = d;
    e[len].g = r[x].first;
    r[x].first = len;

    len++;

    e[len].x = y;
    e[len].y = x;
    e[len].d = 0;
    e[len].g = r[y].first;
    r[y].first = len;

    e[len].f = len - 1;
    e[len - 1].f = len;
}
bool bfs()
{
    int tou = 1, wei = 2;
    for (int i = 1; i <= 2000; i++)
    {
        r[i].h = 0;
    }
    r[st].h = 1;
    r[ed].h = 0;

    q[1] = st;

    while (tou < wei)
    {
        int x = q[tou];
        for (int i = r[x].first; i > 0; i = e[i].g)
        {
            int y = e[i].y;
            if (e[i].d > 0 && r[y].h == 0)
            {
                r[y].h = r[x].h + 1;
                q[wei] = y;
                wei++;
            }
        }
        tou++;
    }
    if (r[ed].h > 0)
    {
        return true;
    }
    return false;
}
int dfs(int x, int f)
{
    if (x == ed)
    {
        return f;
    }
    int tt = 0;
    for (int i = r[x].first; i > 0; i = e[i].g)
    {
        int y = e[i].y;
        if (r[x].h + 1 == r[y].h && tt <= f && e[i].d > 0)
        {
            int my = dfs(y, min(e[i].d, f - tt));
            tt += my;
            e[i].d -= my;
            e[e[i].f].d += my;
        }
    }
    if (tt == 0)
    {
        r[x].h = 0;
    }
    return tt;
}
int dinic()
{
    int ans = 0;
    while (bfs() == true)
    {
        ans += dfs(st, inf);
    }
    return ans;
}
int main()
{
    int t = 0;
    scanf("%d", &t);
    while (t--)
    {
        int tot = 0;
        scanf("%d", &n);
        memset(q, 0, sizeof(q));
        memset(e, 0, sizeof(e));
        memset(r, 0, sizeof(r));
        len = 0;
        int rn[101], ho[101];
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &rn[i]);
            if (rn[i] == 1)
            {
                ins(i + n, ed, 1);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &ho[i]);
            if ((rn[i] == 1 && ho[i] == 0) || (rn[i] == 0))
            {
                ins(st, i, 1);
                tot++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int dx = 0;
                scanf("%d", &dx);
                if (dx == 1 || i == j)
                {
                    ins(i, j + n, 1);
                }
            }
        }
        if (dinic() >= tot)
        {
            printf("^_^\n");
        }
        else
        {
            printf("T_T\n");
        }
    }
    return 0;
}