#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

ll n, h;
ll a[1010], tmp[1010];

inline int check(int mid)
{
    for (int i = 1; i <= mid; i++)
        tmp[i] = a[i];
    std::sort(tmp + 1, tmp + mid + 1);
    ll left = h;
    for (int i = mid; i >= 1;)
    {
        if (left < tmp[i])
            return 0;
        left -= tmp[i];
        i -= 2;
    }
    return 1;
}

int main()
{
    scanf("%I64d%I64d", &n, &h);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    if (a[1] > h)
        return 0 * printf("0");
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}
