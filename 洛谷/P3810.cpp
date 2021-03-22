#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 2e5 + 10;

struct node
{
    int a, b, c, w, ans;
} a[MaxN], b[MaxN];

int n, m, k, cnt[MaxN], ans[MaxN];

bool cmp1(node a, node b)
{
    if (a.a == b.a)
    {
        if (a.b == b.b)
            return a.c < b.c;
        else
            return a.b < b.b;
    }
    return a.a < b.a;
}

bool cmp2(node a, node b)
{
    if (a.b == b.b)
        return a.c < b.c;
    return a.b < b.b;
}

struct BIT
{
    int c[MaxN];
    int lowbit(int x) { return x & (-x); }
    void add(int x, int v)
    {
        while (x <= k)
            c[x] += v, x += lowbit(x);
    }
    int query(int x)
    {
        int ret = 0;
        while (x)
            ret += c[x], x -= lowbit(x);
        return ret;
    }
} T;

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

void solve(int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1, now = l;
    solve(l, mid), solve(mid + 1, r);
    std::sort(a + l, a + mid + 1, cmp2);
    std::sort(a + mid + 1, a + r + 1, cmp2);
    for (int i = mid + 1; i <= r; i++)
    {
        while (a[now].b <= a[i].b && now <= mid)
            T.add(a[now].c, a[now].w), ++now;
        a[i].ans += T.query(a[i].c);
    }
    for (int i = l; i < now; i++)
        T.add(a[i].c, -a[i].w);
}

signed main()
{
    int c = 0;
    m = read(), k = read();
    for (int i = 1; i <= m; i++)
        b[i].a = read(), b[i].b = read(), b[i].c = read();
    std::sort(b + 1, b + m + 1, cmp1);
    for (int i = 1; i <= m; i++)
    {
        ++c;
        if (b[i].a != b[i + 1].a || b[i].b != b[i + 1].b || b[i].c != b[i + 1].c)
            ++n, a[n] = b[i], a[n].w = c, c = 0;
    }
    solve(1, n);
    for (int i = 1; i <= n; i++)
        ans[a[i].ans + a[i].w - 1] += a[i].w;
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}