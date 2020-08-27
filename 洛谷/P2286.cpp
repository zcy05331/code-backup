#include <bits/stdc++.h>

#define R register
#define ll long long
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll MaxN = 2e5 + 10;
const ll inf = 2147483647ll * 2;

struct node
{
    ll ch[2];
    ll size, cnt, val, rnd;
};

ll n;
ll ans;

struct treap
{
    ll root, cnt;
    node t[MaxN << 1];
    void update(ll x) { t[x].size = t[lc].size + t[rc].size + t[x].cnt; }
    void rotate(ll &x, ll c)
    {
        ll y = t[x].ch[c];
        t[x].ch[c] = t[y].ch[c ^ 1];
        t[y].ch[c ^ 1] = x, update(x), update(x = y);
    }
    void insert(ll &x, ll val)
    {
        if (!x)
        {
            x = ++cnt, t[x].cnt = t[x].size = 1;
            t[x].val = val, t[x].rnd = rand();
            return;
        }
        t[x].size++;
        if (t[x].val == val)
            return (void)(++t[x].cnt);
        ll c = val > t[x].val;
        insert(t[x].ch[c], val);
        if (t[x].rnd > t[t[x].ch[c]].rnd)
            rotate(x, c);
    }
    void del(ll &x, ll val)
    {
        if (!x) return;
        if (t[x].val == val)
        {
            if (t[x].cnt > 1)
                return (void)(t[x].cnt--, t[x].size--);
            ll c = t[lc].rnd > t[rc].rnd;
            if (!lc || !rc)
                x = lc + rc;
            else
                rotate(x, c), del(x, val);
        }
        else
            t[x].size--, del(t[x].ch[val > t[x].val], val);
    }
    ll query_pre(ll x, ll val)
    {
        if (!x) return -inf;
        if (t[x].val >= val)
            return query_pre(lc, val);
        else
            return std::max(t[x].val, query_pre(rc, val));
    }
    ll query_sub(ll x, ll val)
    {
        if (!x) return inf;
        if (t[x].val <= val)
            return query_sub(rc, val);
        else
            return std::min(t[x].val, query_sub(lc, val));
    }
} T[2];

ll abs(ll x) { return ((x > 0) ? x : (-x)); }

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
    n = read();
    while (n--)
    {
        ll op = read(), x = read();
        if (op == 1)
        {
            if (!T[0].t[T[0].root].size)
                T[1].insert(T[1].root, x);
            else
            {
                ll pre = T[0].query_pre(T[0].root, x);
                ll sub = T[0].query_sub(T[0].root, x);
                if (abs(x - pre) <= abs(sub - x) && pre != -inf)
                    T[0].del(T[0].root, pre), ans += abs(x - pre);
                else if (abs(x - pre) > abs(sub - x) && sub != inf)
                    T[0].del(T[0].root, sub), ans += abs(sub - x);
                //            	printf("pre = %lld, sub = %lld, ans = %lld\n", pre, sub, ans);
            }
        }
        else
        {
            if (!T[1].t[T[1].root].size)
                T[0].insert(T[0].root, x);
            else
            {
                ll pre = T[1].query_pre(T[1].root, x);
                ll sub = T[1].query_sub(T[1].root, x);
                if (abs(x - pre) <= abs(sub - x) && pre != -inf)
                    T[1].del(T[1].root, pre), ans += abs(x - pre);
                else if (abs(x - pre) > abs(sub - x) && sub != inf)
                    T[1].del(T[1].root, sub), ans += abs(sub - x);
                //                printf("pre = %lld, sub = %lld, ans = %lld\n", pre, sub, ans);
            }
        }
    }
    printf("%lld\n", ans % 1000000);
    return 0;
}