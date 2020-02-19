#include <bits/stdc++.h>

#define ll long long

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, m;
        ll x[10], y[10];
        scanf("%I64d%I64d", &n, &m);
        for (int i = 1; i <= 4; i++)
            scanf("%I64d%I64d", &x[i], &y[i]), std::swap(x[i], y[i]);
        ll w = (n * m + 1) / 2, b = (n * m) - w;
        ll c1 = (x[2] - x[1] + 1) * (y[2] - y[1] + 1) - (((x[2] - x[1] + 1) * (y[2] - y[1] + 1) + ((x[1] % 2) == (y[1] % 2))) / 2);
        w += c1, b -= c1;
        ll c2 = (((x[4] - x[3] + 1) * (y[4] - y[3] + 1) + ((x[3] % 2) == (y[3] % 2))) / 2);
        w -= c2, b += c2;
        ll c3 = 0;
        if (((std::min(x[2], x[4]) >= std::max(x[1], x[3])) && ((std::min(y[2], y[4]) >= std::max(y[1], y[3])))))
            c3 = ((std::min(x[2], x[4]) - std::max(x[1], x[3]) + 1) * (std::min(y[2], y[4]) - std::max(y[1], y[3]) + 1)) - ((((std::min(x[2], x[4]) - std::max(x[1], x[3]) + 1) * (std::min(y[2], y[4]) - std::max(y[1], y[3]) + 1))) + ((std::max(x[1], x[3]) % 2) == (std::max(y[1], y[3]) % 2))) / 2;
        c3 = std::max(c3, 0ll);
        w -= c3, b += c3;
        printf("%I64d %I64d\n", w, b);
    }
    return 0;
}