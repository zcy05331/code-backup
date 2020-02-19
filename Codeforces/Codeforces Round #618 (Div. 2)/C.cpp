#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

ll n, a[MaxN], cnt[50];

int main()
{
    scanf("%I64d", &n);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%I64d", &a[i]);
        for (int j = 0; j <= 31; j++)
            if ((a[i] >> j) & 1)
                cnt[j]++;
    }
    for (ll i = 31; ~i; i--)
    {
        if (cnt[i] == 1)
        {
            int pos = 0;
            for (ll j = 1; j <= n; j++)
                if ((a[j] >> i) & 1)
                    pos = j;
            printf("%I64d ", a[pos]);
            for (int j = 1; j < pos; j++)
                printf("%I64d ", a[j]);
            for (int j = pos + 1; j <= n; j++)
                printf("%I64d ", a[j]);
            return 0;
        }
    }
    for (ll i = 1; i <= n; i++)
        printf("%I64d ", a[i]);
    return 0;
}
