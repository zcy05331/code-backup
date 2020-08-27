#include <bits/stdc++.h>

#define R register
#define ll long long

const ll MaxN = 3e5 + 10;

ll n, q, x, a[MaxN], c[MaxN];

ll lowbit(ll x) {return x & -x;}

void add(ll pos, ll val)
{
    while(pos <= (1 << n))
        c[pos] += val, pos += lowbit(pos);
}

ll sum(ll pos)
{
    ll res = 0;
    while(pos)
        res += c[pos], pos -= lowbit(pos);
    return res;
}

ll query(ll l, ll r, ll ql, ll qr)
{
    if(l > qr || ql > r) return 0;
    // prllf("[%d %d]\n", l, r);
    if (ql <= l && r <= qr) 
    {
        ll pow = r - l + 1;
        ll l1 = (l ^ x) - (l ^ x) % pow;
        return sum(l1 + pow) - sum(l1);
    }
    ll mid = (l + r) >> 1;
    return query(l, mid, ql, qr) + query(mid + 1, r, ql, qr);
}

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
    n = read(), q = read();
    for(ll i = 0; i < (1 << n); i++)
        a[i] = read(), add(i + 1, a[i]);
    while(q--)
    {
        ll op = read();
        if(op == 1)
        {
            ll i = read() - 1, k = read();
            add((i ^ x) + 1, -a[i ^ x]), a[i ^ x] = k, add((i ^ x) + 1, k);
        }
        else if(op == 2)
        {
            ll k = read();
            x ^= ((1 << k) - 1);
        }
        else if(op == 3)
        {
            ll k = read();
            x ^= (1 << k);
        }
        else if(op == 4)
        {
            ll l = read() - 1, r = read() - 1;
            printf("%lld\n", query(0, (1 << n) - 1, l, r));
        }
    }
    return 0;
}
