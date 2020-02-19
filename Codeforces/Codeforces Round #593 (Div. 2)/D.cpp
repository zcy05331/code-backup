#include <bits/stdc++.h>
const int MaxN = 1e5 + 10;
int n, m, k;
std::vector<int> a[MaxN], b[MaxN];
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
int px = 1, py = 1, xmin = 0, xmax = 233333, ymin = 0, ymax = 233333, sum = 1;
int main()
{
    n = read(), m = read(), k = read();
    for (int i = 1; i <= k; ++i)
    {
        int x = read(), y = read();
        if (x == 1 && y == 1)
            return 0 * printf("No");
        a[x].push_back(y), b[y].push_back(x);
    }
    // for (int i = 1; i <= n + 10; i++)
    //     a[i].push_back(m + 1), a[i].push_back(0);
    // for (int i = 1; i <= m + 10; i++)
    //     b[i].push_back(n + 1), b[i].push_back(0);
    for (int i = 1; i <= n; ++i)
        sort(a[i].begin(), a[i].end());
    for (int i = 1; i <= m; ++i)
        sort(b[i].begin(), b[i].end());
    for (int i = 1; i <= 8 * 1000005; ++i)
    {
        if (i % 4 == 1)
        {
            int tmp = 233333;
            for (int j = 0; j < a[px].size(); ++j)
            {
                if (a[px][j] > py)
                {
                    tmp = a[px][j];
                    break;
                }
            }
            int tmpp = std::min(tmp - 1, (ymax == 233333) ? n : ymax - 1);
            if (tmpp <= py)
                goto end;
            sum += tmpp - py;
            xmin = px + 1;
            py = tmpp;
        }
        if (i % 4 == 2)
        {
            int tmp = 233333;
            for (int j = 0; j < b[py].size(); ++j)
            {
                if (b[py][j] > px)
                {
                    tmp = b[py][j];
                    break;
                }
            }
            int tmpp = std::min(tmp - 1, (xmax == 233333) ? n : xmax - 1);
            if (tmpp <= px)
                goto end;
            sum += tmpp - px;
            ymax = py - 1;
            px = tmpp;
        }
        if (i % 4 == 3)
        {
            int tmp = 0;
            for (int j = a[px].size() - 1; j >= 0; --j)
                if (a[px][j] < py)
                {
                    tmp = a[px][j];
                    break;
                }
            int tmpp = std::max(tmp + 1, (ymin == 0) ? 1 : ymin + 1);
            if (tmpp >= py)
                goto end;
            sum += py - tmpp;
            xmax = px - 1;
            py = tmpp;
        }
        if (i % 4 == 0)
        {
            int tmp = 0;
            for (int j = b[py].size() - 1; j >= 0; --j)
                if (b[py][j] < px)
                {
                    tmp = b[py][j];
                    break;
                }
            int tmpp = std::max(tmp + 1, (xmin == 0) ? 1 : xmin + 1);
            if (tmpp >= px)
                goto end;
            sum += px - tmpp;
            ymin = py + 1;
            px = tmpp;
        }
    }
end:;
    if (1ll * n * m <= k + 0ll + sum)
        puts("Yes");
    else
        puts("No");
    return 0;
}