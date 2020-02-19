# include <bits/stdc++.h>
# define getpos(x) ((x - 1) / size + 1)
const int MaxN = 2e6 + 10;
struct query
{
    int l, r;
    int id, pre;
};
struct change
{
    int pos, val;
};
query q[MaxN];
change c[MaxN];
int n, m, qcnt, ccnt, size;
int a[MaxN], col[MaxN], ans[MaxN], cnt;
int cmp(const query &a, const query &b)
{
    if (a.l != b.l)
        return getpos(a.l) < getpos(b.l);
    if (a.r != b.r)
        return getpos(a.r) < getpos(b.r);
    return a.pre < b.pre;
}
inline int read()
{
    char ch = getchar();
    register int x = 0;
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
inline void add(int x)
{
    ++col[a[x]];
    if(col[a[x]] == 1)
        ++cnt;
}
inline void del(int x)
{
    --col[a[x]];
    if(col[a[x]] == 0)
        --cnt;
}
inline void modify(int now, int x)
{
    if(c[now].pos >= q[x].l && q[x].r >= c[now].pos)
    {
        col[a[c[now].pos]]--;
        if (col[a[c[now].pos]] == 0)
            --cnt;
        col[c[now].val]++;
        if(col[c[now].val] == 1)
            ++cnt;
    }
    std::swap(c[now].val, a[c[now].pos]);
}
inline void solve()
{
    int l = 1, r = 0, now = 0;
    for(int i = 1; i <= qcnt; i++)
    {
        while(l > q[i].l)
            l--, add(l);
        while (r < q[i].r)
            r++, add(r);
        while (l < q[i].l)
            del(l), l++;
        while (r > q[i].r)
            del(r), r--;
        while(now < q[i].pre)
            ++now, modify(now, i);
        while(now > q[i].pre)
            modify(now, i), now--;
        ans[q[i].id] = cnt;
    }
}
int main()
{
    n = read(), m = read();     
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++)
    {
        std::string op;
        std::cin >> op;
        if(op == "Q")
        {
            ++qcnt;
            q[qcnt].l = read(), q[qcnt].r = read();
            q[qcnt].pre = ccnt, q[qcnt].id = qcnt;
        }
        else
        {
            ++ccnt;
            c[ccnt].pos = read(), c[ccnt].val = read();
        }
    }
    size = ceil(exp((log(n) + log(ccnt) / 3)));
    std::sort(q + 1, q + qcnt + 1, cmp);
    solve();
    for(int i = 1; i <= qcnt; i++)
        printf("%d\n", ans[i]);
    return 0;
}