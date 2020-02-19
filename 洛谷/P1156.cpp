#include <bits/stdc++.h>
const int MaxN = 100010;
struct node
{
    int t, f, h;
};
node a[MaxN];
int d, g, f[MaxN];
inline int cmp(node a, node b)
{
    return a.t < b.t;
}
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
    d = read(), g = read();
    for (int i = 1; i <= g; i++)
        a[i].t = read(), a[i].f = read(), a[i].h = read();
    std::sort(a + 1, a + g + 1, cmp);
    f[0] = 10;
    for (int i = 1; i <= g; i++)
    {
        for (int j = d; j >= 0; j--)
        {
            if (f[j] >= a[i].t)
            {
                if (j + a[i].h >= d)
                    return 0 * printf("%d\n", a[i].t);
                f[j + a[i].h] = std::max(f[j], f[j + a[i].h]);
                f[j] += a[i].f;
            }
        }
    }
    printf("%d\n", f[0]);
    return 0;
}
