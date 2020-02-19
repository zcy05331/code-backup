#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxM = 21;
const int MaxN = 4e5 + 10;

ll n, a[MaxN], f[1 << MaxM];
ll cnt[MaxM], w[MaxM][MaxM];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
        for (int j = 1; j <= 20; j++)
            if (a[i] != j)
                w[j][a[i]] += cnt[j];
    }
    int lim = (1 << 20) - 1;
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for (int i = 0; i <= lim; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i & (1 << j))
            {
                ll sum = 0, now = i ^ (1 << j);
                for (int k = 0; k < 20; k++)
                    if (now & (1 << k))
                        sum += w[j + 1][k + 1];
                f[i] = std::min(f[i], f[now] + sum);
            }
        }
    }
    printf("%lld\n", f[lim]);
    return 0;
}
