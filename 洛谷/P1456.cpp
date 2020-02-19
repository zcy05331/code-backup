#include <bits/stdc++.h>
const int MaxN = 100010;
struct heap
{
    int ch[MaxN][2], val[MaxN], dis[MaxN], f[MaxN];
    int merge(int x, int y)
    {
        if (x == 0 || y == 0)
            return x + y;
        if (val[x] > val[y] || (val[x] == val[y] && x > y))
            std::swap(x, y);
        ch[x][1] = merge(ch[x][1], y);
        f[ch[x][1]] = x;
        if (dis[ch[x][0]] < dis[ch[x][1]])
            std::swap(ch[x][0], ch[x][1]);
        dis[x] = dis[ch[x][1]] + 1;
        return x;
    }
    int getf(int x)
    {
        while (f[x])
            x = f[x];
        return x;
    }
    void pop(int x)
    {
        val[x] = -1;
        f[ch[x][0]] = f[ch[x][1]] = 0;
        merge(ch[x][0], ch[x][1]);
    }
} T;

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &T.val[i]), T.val[i] = -T.val[i];
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int fx = T.getf(x), fy = T.getf(y);
        if(fx == fy)
        {
            printf("-1\n");
            continue;
        }
        else
        {
            T.val[fx] /= 2, T.val[fy] /= 2;
            T.merge(fx, fy);
            int fxy = T.getf(fy);
            printf("%d\n", -T.val[fxy]);
        }
    }
    return 0;
}