
#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

int n;
int x[MaxN], y[MaxN], f[MaxN][5];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int flag = 1, lx = -100000, ly = -100000, rx = 100000, ry = 100000;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            for (int j = 1; j <= 4; j++)
            {
                scanf("%d", &f[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (f[i][1] == 0)
            {
                if (rx < x[i])
                    flag = 0;
                else
                    lx = cmax(lx, x[i]);
            }
            if (f[i][2] == 0)
            {
                if (ly > y[i])
                    flag = 0;
                else
                    ry = cmin(ry, y[i]);
            }
            if (f[i][3] == 0)
            {
                if (lx > x[i])
                    flag = 0;
                else
                    rx = cmin(rx, x[i]);
            }
            if (f[i][4] == 0)
            {
                if (ry < y[i])
                    flag = 0;
                else
                    ly = cmax(ly, y[i]);
            }
        }
        if (!flag)
            printf("0\n");
        else
            printf("1 %d %d\n", lx, ly);
    }
    return 0;
}
