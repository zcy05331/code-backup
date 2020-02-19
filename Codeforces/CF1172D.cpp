#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e3 + 10;

int n;
int r[MaxN], c[MaxN];
int pr[MaxN], pc[MaxN];
std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> ans;

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

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        r[i] = read(), pr[r[i]] = i;
    for (int i = 1; i <= n; i++)
        c[i] = read(), pc[c[i]] = i;
    for (int i = n; i > 1; i--)
    {
        if (r[i] == i && c[i] == i)
            continue;
        else
        {                              
            ans.push_back(mp(mp(r[i], i), mp(i, c[i])));
            pr[r[i]] = pr[i];
            r[pr[i]] = r[i];
            pc[c[i]] = pc[i];
            c[pc[i]] = c[i];
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
    return 0;
}