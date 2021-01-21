#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ll long long
#define pair std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define getl(i) ((i - 1) * siz + 1)
#define getr(i) (std::min(n, i * siz))
#define id(x) (((x - 1) / siz) + 1)
#define meow(cat...) fprintf(stderr, cat)

const int MaxB = 8e2 + 10;
const int MaxN = 1e5 + 10;

pair v[MaxB][MaxB];
ll ans, f[MaxB][MaxB];
int len[MaxB], pre[MaxN], cnt[MaxB][MaxN], suf[MaxN];
int n, m, siz, num, a[MaxN], Id[MaxN], bl[MaxN], br[MaxN];

struct BIT
{
    int c[MaxN];
    int lowbit(int x) { return x & (-x); }
    void add(int x, int val)
    {
        while (x <= n)
            c[x] += val, x += lowbit(x);
    }
    int query(int x)
    {
        int ret = 0;
        while (x)
            ret += c[x], x -= lowbit(x);
        return ret;
    }
} T;

void print(ll x)
{
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + 48);
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while ('0' <= ch && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int ta[MaxB], tb[MaxB];

inline ll query(int l1, int r1, int l2, int r2)
{
    int lena = 0, lenb = 0;
    int L = Id[l1], R = Id[l2];
    for (int i = 1; i <= len[L]; i++)
    {
        pair x = v[L][i];
        if (x.second >= l1 && x.second <= r1)
            ta[++lena] = x.first;
    }
    for (int i = 1; i <= len[R]; i++)
    {
        pair x = v[R][i];
        if (x.second >= l2 && x.second <= r2)
            tb[++lenb] = x.first;
    }
    ll ans = 0;
    int A = 1, B = 1;
    while (A <= lena && B <= lenb)
    {
        if (A <= lena)
        {
            if (ta[A] < tb[B] || B > lenb)
                ++A;
            else
                ++B, ans += lena - A + 1;
        }
        else
            ++B;
    }
    return ans;
};

signed main()
{
    // freopen("sqrt.in", "r", stdin);
    // freopen("sqrt.out", "w", stdout);
    n = read(), m = read();
    siz = 165, num = id(n);
    for (int i = 1; i <= n; i++)
        a[i] = read(), Id[i] = id(i);
    for (int i = 1; i <= num; i++)
    {
        bl[i] = getl(i), br[i] = getr(i);
        len[i] = br[i] - bl[i] + 1;
    }
    for (int i = 1; i <= n; i++)
        v[Id[i]][i - bl[Id[i]] + 1] = mp(a[i], i);
    for (int i = 1; i <= num; i++)
        std::sort(v[i] + 1, v[i] + len[i] + 1);
    for (int i = 1; i <= num; i++)
    {
        int l = bl[i], r = br[i];
        for (int j = l; j <= r; ++j)
            cnt[i][a[j]]++;
        for (int j = 1; j <= n; ++j)
            cnt[i][j] += cnt[i - 1][j];
    }
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= n; ++j)
            cnt[i][j] += cnt[i][j - 1];
    for (int i = 1; i <= num; i++)
    {
        int l = bl[i], r = br[i], x = 0, y;
        for (int j = l; j <= r; ++j)
        {
            y = T.query(n) - T.query(a[j]);
            x += y, pre[j] = x, T.add(a[j], 1);
        }
        f[i][i] = x;
        for (int j = l; j <= r; ++j)
        {
            y = T.query(a[j] - 1), suf[j] = x;
            x -= y, T.add(a[j], -1);
        }
    }
    // for(ll i = 1; i <= n; i++)
    //     meow("%d %d %d\n", i, pre[i], suf[i]);
    for (int len = 1; len < num; len++)
    {
        int x = num - len + 1;
        for (int i = 1; i <= x; i++)
        {
            int j = i + len;
            f[i][j] = f[i + 1][j] + f[i][j - 1];
            if (i + 1 <= j - 1) f[i][j] -= f[i + 1][j - 1];
            f[i][j] += query(bl[i], br[i], bl[j], br[j]);
        }
    }
    // meow("xzakioi!\n");
    for (int i = 1; i <= m; i++)
    {
        ll now = 0;
        int l = read() ^ ans, r = read() ^ ans;
        int L = Id[l], R = Id[r], Ll, rr, LL, RR;
        if (L == R)
        {
            rr = br[R];
            if (r == rr)
                now = suf[l];
            else
            {
                now = suf[l] - suf[r + 1];
                now -= query(l, r, r + 1, rr);
            }
        }
        else if (R == L + 1)
        {
            Ll = bl[R], rr = br[L];
            now = suf[l] + pre[r];
            now += query(l, rr, Ll, r);
        }
        else
        {
            
            LL = bl[R], RR = br[L], rr = br[R - 1];
            now = suf[l] + f[L + 1][R - 1];
            now += query(l, RR, LL, r) + pre[r];
            for (int i = l; i <= RR; i++)
                now += cnt[R - 1][a[i]] - cnt[L][a[i]];
            for (int i = LL; i <= r; i++)
            {
                now += cnt[R - 1][n] - cnt[R - 1][a[i]];
                now -= cnt[L][n] - cnt[L][a[i]];
            }
        }
        ans = now, print(ans), putchar('\n');
    }
    meow("used %d ms\n", clock());
    return 0;
}