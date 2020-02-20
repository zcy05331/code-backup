#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int Max = MaxN * 50;

int n;
ll ans, ans1, ans2;

struct node
{
    int sum, lc, rc;
};

struct SegmentTree
{
    int cnt;
    node t[Max];
    void insert(int &rt, int l, int r, int pos)
    {
        rt = ++cnt, t[rt].sum++;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        if (pos <= mid)
            insert(t[rt].lc, l, mid, pos);
        else
            insert(t[rt].rc, mid + 1, r, pos);
    }
    int merge(int x, int y, int l, int r)
    {
        if (!x || !y)
            return x + y;
        if (l == r)
        {
            t[x].sum += t[y].sum;
            return x;
        }
        int mid = (l + r) >> 1;
        ans1 += t[t[x].lc].sum * 1ll * t[t[y].rc].sum;
        ans2 += t[t[x].rc].sum * 1ll * t[t[y].lc].sum;
        t[x].lc = merge(t[x].lc, t[y].lc, l, mid);
        t[x].rc = merge(t[x].rc, t[y].rc, mid + 1, r);
        t[x].sum = t[t[x].lc].sum + t[t[x].rc].sum;
        return x;
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

int solve()
{
    int pos, val = read();
    if (val)
        T.insert(pos, 1, n, val);
    else
    {
        int lc = solve(), rc = solve();
        ans1 = ans2 = 0, pos = T.merge(lc, rc, 1, n), ans += std::min(ans1, ans2);
    }
    return pos;
}

int main()
{
    n = read(), solve();
    printf("%lld\n", ans);
    return 0;
}
