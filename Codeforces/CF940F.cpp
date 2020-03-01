#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct query
{
    int l, r;
    int pre, id;
};

struct change
{
    int pos, val;
};

query q[MaxN];
change c[MaxN];
int n, m, num, qcnt, ccnt, size;
int a[MaxN], b[MaxN], ans[MaxN], pos[MaxN], col[MaxN], cnt[MaxN];

void add(int c) { --cnt[col[c]], ++cnt[++col[c]]; }

void del(int c) { --cnt[col[c]], ++cnt[--col[c]]; }

void modify(int now, int x)
{
    if (q[x].l <= c[now].pos && c[now].pos <= q[x].r)
        del(a[c[now].pos]), add(c[now].val);
    std::swap(a[c[now].pos], c[now].val);
}

void prework()
{
    std::sort(b + 1, b + n + ccnt + 1);
    num = std::unique(b + 1, b + n + ccnt + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + num + 1, a[i]) - b;
    for(int i = 1; i <= ccnt; i++)
        c[i].val = std::lower_bound(b + 1, b + num + 1, c[i].val) - b;
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

int cmp(query a, query b)
{
    if (pos[a.l] != pos[b.l])
        return pos[a.l] < pos[b.l];
    if (pos[a.r] != pos[b.r])
        return pos[a.r] < pos[b.r];
    return a.pre < b.pre;
};

void solve()
{
    int l = 1, r = 0, pos = 0, now = 0;
    for (int i = 1; i <= qcnt; i++)
    {
        while (l > q[i].l)
            --l, add(a[l]);
        while (r < q[i].r)
            ++r, add(a[r]);
        while (l < q[i].l)
            del(a[l]), ++l;
        while (r > q[i].r)
            del(a[r]), --r;
        while (pos < q[i].pre)
            ++pos, modify(pos, i);
        while (pos > q[i].pre)
            modify(pos, i), --pos;
        for (now = 1; cnt[now]; ++now)
            ;
        ans[q[i].id] = now;
    }
}

int main()
{
    n = read(), m = read(), size = pow(n, 0.66);
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = read(), pos[i] = (i - 1) / size + 1;
    for (int i = 1; i <= m; i++)
    {
        int op = read();
        if (op == 1)
        {
            ++qcnt, q[qcnt].l = read(), q[qcnt].r = read();
            q[qcnt].pre = ccnt, q[qcnt].id = qcnt;
        }
        else
            ++ccnt, c[ccnt].pos = read(), c[ccnt].val = b[n + ccnt] = read();
    }
    prework();
    std::sort(q + 1, q + qcnt + 1, cmp), solve();
    for (int i = 1; i <= qcnt; i++)
        printf("%d\n", ans[i]);
    return 0;
}
