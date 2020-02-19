#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
const double delta = 0.999;
const int MaxN = 20;
int n, ans = 0x3f3f3f3f;
double t = 10000000.0;
int pos[MaxN], fri[MaxN][4], g[MaxN][MaxN];
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
inline int calc()
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        ret += abs(pos[i] - pos[fri[i][1]]);
        ret += abs(pos[i] - pos[fri[i][2]]);
        ret += abs(pos[i] - pos[fri[i][3]]);
    }
    return ret / 2;
}
inline void SA()
{
    t = 1.0;
    while (t > 1e-10)
    {
        int x = rand() % n + 1, y = rand() % n + 1;
        std::swap(pos[x], pos[y]);
        int tmp = calc();
        int del = tmp - ans;
        if (del < 0)
            ans = tmp;
        else if (exp(-del / t) * RAND_MAX <= rand())
            std::swap(pos[x], pos[y]);
        t *= delta;
    }
}
int main()
{
    n = read();
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
    {
        pos[i] = i;
        for (int j = 1; j <= 3; j++)
            fri[i][j] = read(), g[i][fri[i][j]] = 1, g[fri[i][j]][i] = 1;
    }
    for (int i = 1; i <= 100; i++)
        SA();
    printf("%d\n", ans);
    return 0;
}
