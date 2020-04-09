#pragma GCC optimize(2)
#include <bits/stdc++.h>
// #pragma diagnostic(error, "-Ofast")

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

using namespace std;
const int MaxN = 1e6 + 10;

struct node
{
    ll sum;
    int max, sec, cnt, tag;
};

node t[MaxN << 2];
int n, m, a[MaxN];

inline void pushup(int id)
{
    const int lc = id << 1, rc = id << 1 | 1;
    t[id].sum = t[lc].sum + t[rc].sum;
    if (t[lc].max == t[rc].sum)
    {
        t[id].cnt = t[lc].cnt + t[rc].cnt;
        t[id].max = t[lc].max, t[id].sec = max(t[lc].sec, t[rc].sec);
    }
    else if (t[lc].max > t[rc].max)
    {
        t[id].sec = max(t[lc].sec, t[rc].max);
        t[id].max = t[lc].max, t[id].cnt = t[lc].cnt;
    }
    else
    {
        t[id].sec = max(t[lc].max, t[rc].sec);
        t[id].max = t[rc].max, t[id].cnt = t[rc].cnt;
    }
}
void build(int id = 1, int l = 1, int r = n)
{
    t[id].tag = -1;
    if (l == r)
    {
        t[id].max = t[id].sum = a[l];
        t[id].cnt = 1, t[id].sec = -1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
    pushup(id);
}
inline void pushtag(int id, int val)
{
    if (t[id].max <= val) return;
    t[id].sum += (1ll * val - t[id].max) * t[id].cnt;
    t[id].max = t[id].tag = val;
}
inline void pushdown(int id)
{
    if (t[id].tag == -1) return;
    pushtag(id << 1, t[id].tag);
    pushtag(id << 1 | 1, t[id].tag), t[id].tag = -1;
}
void setval(int id, int l, int r, int L = 1, int R = n, int val = 0)
{
    if (t[id].max <= val) return;
    if (l <= L && R <= r && val > t[id].sec)
        return pushtag(id, val);
    pushdown(id);
    int mid = (L + R) >> 1;
    if (l <= mid) setval(id << 1, l, r, L, mid, val);
    if (r > mid) setval(id << 1 | 1, l, r, mid + 1, R, val);
    pushup(id);
}
int query_max(int id, int l, int r, int L = 1, int R = n)
{
    if (l <= L && R <= r) return t[id].max;
    int mid = (L + R) >> 1, x = -1, y = -1;
    pushdown(id);
    if (l <= mid) x = query_max(id << 1, l, r, L, mid);
    if (r > mid) y = query_max(id << 1 | 1, l, r, mid + 1, R);
    return max(x, y);
}
ll query_sum(int id, int l, int r, int L = 1, int R = n)
{
    if (l <= L && R <= r) return t[id].sum;
    ll res = 0;
    int mid = (L + R) >> 1;
    pushdown(id);
    if (l <= mid) res += query_sum(id << 1, l, r, L, mid);
    if (r > mid) res += query_sum(id << 1 | 1, l, r, mid + 1, R);
    return res;
}

char nc()
{
    static char buf[1000000], *p = buf, *q = buf;
    return p == q && (q = (p = buf) + fread(buf, 1, 1000000, stdin), p == q) ? EOF : *p++;
}

inline void write(int x)
{
    if (x < 0) x = ~x + 1, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void write(ll x)
{
    if (x < 0) x = ~x + 1, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int read()
{
    register int res = 0;
    char c = nc();
    while (!isdigit(c))
        c = nc();
    while (isdigit(c))
        res = res * 10 + c - '0', c = nc();
    return res;
}

void solve()
{
    n = read(), m = read();
    for (register int i = 1; i <= n; ++i)
        a[i] = read();
    build();
    for (register int i = 1; i <= m; ++i)
    {
        int op = read(), l = read(), r = read(), x;
        if (op == 0)
            x = read(), setval(1, l, r, 1, n, x);
        else if (op == 1)
            write(query_max(1, l, r)), puts("");
        else
            write(query_sum(1, l, r)), puts("");
    }
}

signed main()
{
    freopen("5306.in", "r", stdin);
    freopen("5306.out", "w", stdout);
    register int t = read();
    while (t--)
        solve();
    std::cerr << clock();
    return 0;
}
