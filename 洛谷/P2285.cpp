#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e4 + 10;

int n, m;
int x[MaxN], y[MaxN], t[MaxN], f[MaxN];

int dist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d%d%d", &t[i], &x[i], &y[i]), f[i] = 1;
    for(int i = 2; i <= m; i++)
        for(int j = 1; j < i; j++)
            if(dist(x[i], y[i], x[j], y[j]) <= (t[i] - t[j]))
                f[i] = std::max(f[i], f[j] + 1);
    int ans = 0;
    for(int i = 1; i <= m; i++)
        ans = std::max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}
