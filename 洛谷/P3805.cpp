#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1.1e7 + 10;

int n, ans, p[MaxN * 3];
char s[MaxN * 3], t[MaxN];

void init()
{
    s[0] = '#', s[1] = '#';
    for (int i = 1; i <= n; i++)
        s[i * 2] = t[i], s[i * 2 + 1] = '#';
    n = n * 2 + 2, s[n] = 0;
}

void manacher()
{
    int mx = 0, mid = 0;
    for (int i = 0; i < n; i++)
    {
        if (mx > i)
            p[i] = std::min(mx - i, p[2 * mid - i]);
        else
            p[i] = 1;
        while (i - p[i] && s[i - p[i]] == s[i + p[i]])
            ++p[i];
        if (i + p[i] > mx) mx = i + p[i], mid = i;
        ans = std::max(ans, p[i] - 1);
    }
}

signed main()
{
    scanf("%s", t + 1), n = strlen(t + 1);
    init(), manacher(), printf("%d\n", ans);
    return 0;
}
