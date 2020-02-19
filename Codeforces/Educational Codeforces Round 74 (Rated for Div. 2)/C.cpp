#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

ll n, h, q;
ll a[MaxN], f[MaxN][2];

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1ll) + (x << 3ll) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    q = read();
    while (q--)
    {
        ll ans = 0;
        h = read(), n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        a[n + 1] = 0, a[1] = a[2] + 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i + 1] + 1)
            {
                if (a[i] - a[i + 2] <= 2)
                {
                    ++i;
                    a[i + 1] = a[i + 2] + 1;
                    continue;
                }
                else
                {
                    ++ans;
                    a[i + 1] = a[i + 2] + 1;
                    continue;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
