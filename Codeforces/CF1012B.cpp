#include <bits/stdc++.h>
const int MaxN = 500010;
int f[MaxN];
int n, m;
int q;
int getf(int x)
{
    if (f[x] != x)
        f[x] = getf(f[x]);
    return f[x];
}
void merge(int x, int y)
{
    f[getf(x)] = getf(y);
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n + m; i++)
        f[i] = i;
    for (int i = 1; i <= q; i++)
    {
        int r, c;
        scanf("%d%d", &r, &c);
        merge(r, c + n);
    }
    int ans = 0;
    for (int i = 1; i <= n + m; i++)
        if (f[i] == i)
            ans++;
    printf("%d\n", ans - 1);
    return 0;
}