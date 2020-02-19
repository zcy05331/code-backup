#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 5e3 + 10;

int n, ans, f[MaxN];
std::pair<int, int> p[MaxN];

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

inline int cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second > b.second;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        p[i].first = read(), p[i].second = read();
    std::sort(p + 1, p + n + 1, cmp);
    for (int i = n; i >= 1; i--)
    {
        f[i] = 1;
        for (int j = i + 1; j <= n; j++)
            if (p[i].second < p[j].second)
                f[i] = cmax(f[i], f[j] + 1);
    }

    for (int i = 1; i <= n; i++)
        ans = cmax(f[i], ans);
    printf("%d\n", ans);
    return 0;
}
