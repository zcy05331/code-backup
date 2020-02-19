#include <bits/stdc++.h>

#define R register
#define ll long long
#define mul(a, b, mod) (((a) * (b)) % mod)
#define sum(a, b, mod) (((a) + (b)) % mod)

const ll mod = 51061;
const ll MaxN = 1e5 + 10;

ll n, m;

struct LinkCutTree
{
    ll fa[MaxN], sum[MaxN], val[MaxN], rev[MaxN], add[MaxN], mul[MaxN], size[MaxN], ch[MaxN][2];
    inline void pushup(ll x)
    {
        size[x] = size[ch[x][0]] + 1 + size[ch[x][1]];
        sum[x] = (sum[ch[x][0]] + val[x] + sum[ch[x][1]]) % mod;
    }
    inline void pushadd(ll x, ll Val)
    {
        val[x] = sum(val[x], Val, mod);
        add[x] = sum(add[x], Val, mod);
        sum[x] = sum(sum[x], mul(size[x], Val, mod), mod);
    }
    inline void pushmul(ll x, ll Val)
    {
        val[x] = mul(val[x], Val, mod);
        mul[x] = mul(mul[x], Val, mod);
        add[x] = mul(add[x], Val, mod);
        sum[x] = mul(sum[x], Val, mod);
    }
    inline void pushdown(ll x)
    {
        ll l = ch[x][0], r = ch[x][1];
        if (mul[x] != 1)
            pushmul(l, mul[x]), pushmul(r, mul[x]), mul[x] = 1;
        if (add[x])
            pushadd(l, add[x]), pushadd(r, add[x]), add[x] = 0;
        if (rev[x])
        {
            rev[l] ^= 1, rev[r] ^= 1;
            rev[x] = 0, std::swap(ch[x][0], ch[x][1]);
        }
        sum[x] %= mod, val[x] %= mod;
    }
    inline ll check(ll x) {return (ch[fa[x]][1] == x);}
    inline ll isroot(ll x) {return (ch[fa[x]][0] != x && ch[fa[x]][1] != x);}
    inline void rotate(ll x)
    {
        ll f = fa[x], gf = fa[f], tp = check(x);
        (!isroot(f)) ? (ch[gf][check(f)] = x) : 0;
        fa[ch[x][tp ^ 1]] = f, fa[f] = x, fa[x] = gf;
        ch[f][tp] = ch[x][tp ^ 1], ch[x][tp ^ 1] = f, pushup(f), pushup(x);
    }
    inline void update(ll x)
    {
        if(!isroot(x))
            update(fa[x]);
        pushdown(x);
    }
    inline void splay(ll x)
    {
        update(x);
        for(ll y = 0; y = fa[x], !isroot(x); rotate(x))
            if(!isroot(y))
                rotate((check(x) ^ check(y)) ? x : y);
    }
    inline void access(ll x)
    {
        for(ll y = 0; x; y = x, x = fa[x])
            splay(x), ch[x][1] = y, pushup(x);
    }
    inline void makeroot(ll x){access(x), splay(x), rev[x] = 1, pushdown(x);}
    inline ll getroot(ll x)
    {
        access(x), splay(x);
        while(ch[x][0])
            x = ch[x][0];
        return x;
    }
    inline void split(ll x, ll y){makeroot(x), access(y), splay(y);}
    inline void cut(ll x, ll y)
    {
        makeroot(x);
        if(getroot(y) != x || fa[x] != y || ch[x][1])
            return;
        fa[x] = ch[y][0] = 0, pushup(y);
    }
    inline void link(ll x, ll y){makeroot(x), fa[x] = y;}
}T ;

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
int main()
{
    n = read(), m = read();
    for(ll i = 1; i <= n; i++)
        T.val[i] = 1, T.mul[i] = 1;
    for(ll i = 1; i < n; i++)
    {
        ll u = read(), v = read();
        T.link(u, v);
    }
    char ch[2];
    while(m--)
    {
        scanf("%s", ch + 1);
        if(ch[1] == '+')
        {
            ll x = read(), y = read(), val = read() % mod;
            T.split(x, y), T.pushadd(y, val);
        }
        else if(ch[1] == '-')
        {
            ll u1 = read(), v1 = read(), u2 = read(), v2 = read();
            T.cut(u1, v1), T.link(u2, v2);
        }
        else if(ch[1] == '*')
        {
            ll x = read(), y = read(), val = read() % mod;
            T.split(x, y), T.pushmul(y, val);
        }
        else 
        {
            ll x = read(), y = read();
            T.split(x, y), printf("%lld\n", T.sum[y] % mod);
        } 
    }
    return 0;
}
