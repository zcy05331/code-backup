#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 2e5 + 10;

struct query
{
    int op, x, y, k, id;
} q[MaxN], Ql[MaxN], Qr[MaxN];;

std::vector<int> b;
int n, m, cnt, a[MaxN], ans[MaxN];

struct BIT
{
    int c[MaxN];
    int lowbit(int x) { return x & (-x); }
    void add(int x, int v)
    {
        while(x <= n)
            c[x] += v, x += lowbit(x);
    }
    int query(int x)
    {
        int ret = 0;
        while(x)
            ret += c[x], x -= lowbit(x);
        return ret;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
} T;

char get()
{
    char ch = getchar();
    while(!isalpha(ch))
        ch = getchar();
    return ch;
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

void solve(int l, int r, int ql, int qr)
{
    if(l == r)
    {
        for(int i = ql; i <= qr; i++)
            if(q[i].op == 1)
                ans[q[i].id] = l;
        return;
    }
    if(l > r || ql > qr) return;
    int cntl = 0, cntr = 0, mid = (l + r) >> 1;
    for(int i = ql; i <= qr; i++)
    {
        if(q[i].op == 0)
        {
            if(q[i].y <= mid)
                T.add(q[i].x, q[i].k), Ql[++cntl] = q[i];
            else Qr[++cntr] = q[i];
        }
        else
        {
            int t = T.query(q[i].x, q[i].y);
            if(q[i].k <= t) Ql[++cntl] = q[i];
            else q[i].k -= t, Qr[++cntr] = q[i];
        }
    }
    for(int i = 1; i <= cntl; i++)
        if(Ql[i].op == 0) T.add(Ql[i].x, -Ql[i].k);
    for(int i = 1; i <= cntl; i++) q[ql + i - 1] = Ql[i];
    for(int i = 1; i <= cntr; i++) q[ql + cntl + i - 1] = Qr[i];
    solve(l, mid, ql, ql + cntl - 1), solve(mid + 1, r, ql + mid, qr);
}

signed main()
{   
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read(), q[++cnt] = {0, i, };
    for(int i = 1; i <= m; i++)
    {
        int op = get(), x = read(), y = read();
        if(op == 'C')
         {   
             q[++cnt] = {0, y, };
         }

    }
    return 0;
}
