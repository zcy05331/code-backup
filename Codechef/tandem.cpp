#include <bits/stdc++.h>

#define R register
#define ll unsigned long long
#define sum(a, b, mod) (((a) + (b)) % (mod))

const ll base = 131;
const int MaxN = 3e5 + 10;

char s[MaxN];
ll n, cnt, ans, h[MaxN], powm[MaxN];

ll calc(int l, int r) { return h[l] - h[r + 1] * powm[r - l + 1]; }

int suffix(int x, int y)
{
    if (s[x] != s[y])
        return 0;
    int l = 1, r = std::min(n - x + 1, n - y + 1);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (calc(x, x + mid - 1) == calc(y, y + mid - 1))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int prefix(int x, int y)
{
    if (s[x] != s[y])
        return 0;
    int l = 1, r = std::min(x, y);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (calc(x - mid + 1, x) == calc(y - mid + 1, y))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    powm[0] = 1;
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        powm[i] = (powm[i - 1] * base);
    for (int i = n; i; i--)
        h[i] = (h[i + 1] * base + s[i]);
    for (int i = 1; i <= n / 3; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            int x = j, y = j + i, z = j + 2 * i;
            if (z > n)
                continue;
            int lcs = std::min(std::min(suffix(x, y), suffix(y, z)), i);
            int lcp = std::min(std::min(prefix(x, y), prefix(y, z)), i);
            // printf("%d %d %d %d %d\n", x, y, z, lcs, lcp);
            if (lcs + lcp > i)
            {
                cnt += std::min(lcs, lcs + lcp - i);
                if (s[z + lcs] != s[x + lcs - i])
                    ++ans;
            }
        }
    }
    printf("%lld %lld\n", ans, cnt - ans);
    return 0;
}
