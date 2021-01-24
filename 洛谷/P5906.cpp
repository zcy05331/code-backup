#include <bits/stdc++.h>

#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

struct node
{
    int id, l, r;
};

struct query
{
    int l, r;
    int pos, id;
} Q[MaxN];

std::vector<node> v;
int n, m, q, cur, siz, num, now, a[MaxN], b[MaxN], tl[MaxN];
int id[MaxN], lp[MaxN], rp[MaxN], ans[MaxN], tr[MaxN], vi[MaxN];

int cmp(query a, query b)
{
    if (a.pos != b.pos)
        return a.pos < b.pos;
    return a.r < b.r;
}

void addr(int pos)
{
    if (!lp[a[pos]])
        lp[a[pos]] = pos;
    else
        rp[a[pos]] = pos, now = std::max(now, rp[a[pos]] - lp[a[pos]]);
}

void backup(int l, int r)
{
    v.clear();
    for (int i = l; i <= r; i++)
        if (!vi[a[i]])
            v.push_back((node){a[i], lp[a[i]], rp[a[i]]}), vi[a[i]] = 1;
    for (int i = l; i <= r; i++)
        vi[a[i]] = 0;
}

void recovery(int l, int r)
{
    for (auto x : v)
        lp[x.id] = x.l, rp[x.id] = x.r;
    v.clear();
}

void addl(int pos)
{
    int c = a[pos];
    if (!lp[c] && !rp[c])
        rp[c] = pos;
    else
    {
        if (lp[c] && !rp[c])
            rp[c] = lp[c], lp[c] = pos;
        else if (rp[c])
            lp[c] = pos;
        now = std::max(now, rp[c] - lp[c]);
    }
}

void write(int x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
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

int calc(int l, int r)
{
    int ret = 0;
    for (int i = l; i <= r; i++)
        tl[a[i]] = tr[a[i]] = 0;
    for (int i = l; i <= r; i++)
    {
        if (!tl[a[i]])
            tl[a[i]] = i;
        else
            tr[a[i]] = i, ret = std::max(ret, i - tl[a[i]]);
    }
    return ret;
}

int solve(int pos, int id)
{
    int R = std::min(n, id * siz), l = R + 1, r = R;
    now = 0, memset(lp, 0, 4 * (m + 10)), memset(rp, 0, 4 * (m + 10));
    while (::id[Q[pos].l] == id)
    {
        if (::id[Q[pos].l] == ::id[Q[pos].r])
            ans[Q[pos].id] = calc(Q[pos].l, Q[pos].r);
        else
        {
            while (r < Q[pos].r)
                addr(++r);
            cur = now, backup(Q[pos].l, R);
            while (l > Q[pos].l)
                addl(--l);
            ans[Q[pos].id] = now, now = cur,
            l = R + 1, recovery(Q[pos].l, R);
        }
        ++pos;
    }
    return pos;
}

signed main()
{
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    n = read(), siz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] = read();
        id[i] = (i - 1) / siz + 1;
    }
    std::sort(b + 1, b + n + 1);
    m = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
    q = read(), num = (n - 1) / siz + 1;
    for (int i = 1; i <= q; i++)
    {
        Q[i].l = read(), Q[i].r = read();
        Q[i].pos = id[Q[i].l], Q[i].id = i;
    }
    std::sort(Q + 1, Q + q + 1, cmp);
    for (int i = 1, id = 1; i <= num; i++)
        id = solve(id, i);
    for (int i = 1; i <= q; i++)
        write(ans[i]), putchar('\n');
    // meow("csy has aked %d times ioi.\n", clock());
    return 0;
}