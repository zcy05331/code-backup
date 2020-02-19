#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

struct node
{
    int t, l, r;
};

int n, m;
node a[MaxN];

int cmp(node a, node b) { return a.t < b.t; }

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", &a[i].t, &a[i].l, &a[i].r);
        int flag = 1, l = m, r = m;
        std::sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            l = l - (a[i].t - a[i - 1].t), r = r + (a[i].t - a[i - 1].t);
            if (l > a[i].r || r < a[i].l)
                flag = 0;
            l = std::max(l, a[i].l), r = std::min(r, a[i].r);
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}
