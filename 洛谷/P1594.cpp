#include <bits/stdc++.h>
#define ll long long
const int MaxN = 1010;
double f[MaxN];
ll n, l, weight;
ll w[MaxN], v[MaxN], sum[MaxN], m[MaxN][MaxN];
inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
int main()
{
    weight = read(), l = read(), n = read();
    for (int i = 1; i <= n; ++i)
    {
        w[i] = read(), v[i] = read();
        sum[i] = sum[i - 1] + w[i];
        m[i][i] = v[i];
    }
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            m[i][j] = std::min(v[j], m[i][j - 1]);
    for (int i = 1; i <= n; ++i)
    {
        f[i] = (double)l / v[i] + f[i - 1];
        for (int j = i - 1; j >= 1; --j)
            if (sum[i] - sum[j - 1] <= weight)
                f[i] = std::min(f[i], f[j - 1] + (double)l / m[j][i]);
            else
                break;
    }
    printf("%.1lf\n", f[n] * 60.0);
    return 0;
}
