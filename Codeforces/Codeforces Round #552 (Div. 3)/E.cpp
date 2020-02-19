#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 200010;
int n, k;
int a[MaxN], f[MaxN];
int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}
inline void merge(int u, int v)
{
    int fu = getf(u), fv = getf(v);
    if (fu != fv)
        f[fu] = fv;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), f[i] = i;
    return 0;
}
