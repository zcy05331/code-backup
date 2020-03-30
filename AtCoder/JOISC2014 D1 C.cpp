#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int inf = 0x3f3f3f3f;

struct query
{
    ll l, r;
    ll pos, id;
};

query q[MaxN];
ll n, m, siz, num, now;
ll a[MaxN], b[MaxN], cnt[MaxN], tim[MaxN], blo[MaxN], ans[MaxN];

void del(int x) {cnt[a[x]]--;}
void add(int x) {cnt[a[x]]++, now = std::max(now, cnt[a[x]] * b[a[x]]);}

int cmp(query a, query b)
{
    if(a.pos != b.pos)
        return a.pos < b.pos;
    return a.r < b.r;
} 

ll calc(int l, int r)
{
    ll ans = 0;
    for(int i = l; i <= r; i++)
        tim[a[i]] = 0;
    for(int i = l; i <= r; i++)
        tim[a[i]]++, ans = std::max(ans, tim[a[i]] * 1ll * b[a[i]]);
    return ans;
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

int solve(int pos, int id)
{
    int R = std::min(n, id * siz), l = R + 1, r = R;
    now = 0, memset(cnt, 0, sizeof(cnt));
    while(blo[q[pos].l] == id)
    {
        if(blo[q[pos].l] == blo[q[pos].r])
            ans[q[pos].id] = calc(q[pos].l, q[pos].r);
        else
        {
            while(r < q[pos].r) add(++r);
            ll cur = now;
            while(l > q[pos].l) add(--l);
            ans[q[pos].id] = now;
            while(l < R + 1) del(l++), now = cur;
        }
        ++pos;
    }
    return pos;
}

int main()
{   
    n = read(), m = read();
    siz = sqrt(n), num = (n - 1) / siz + 1;
    for(int i = 1; i <= n; i++)
    {
        a[i] = b[i] = read();
        blo[i] = (i - 1) / siz + 1;
    }
    std::sort(b + 1, b + n + 1);
    int tot = std::unique(b + 1, b + n + 1) - b - 1;
    for(int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + tot + 1, a[i]) - b;
    for(int i = 1; i <= m; i++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].pos = blo[q[i].l], q[i].id = i;
    }
    std::sort(q + 1, q + m + 1, cmp);
    for(int i = 1, id = 1; i <= num; i++)
        id = solve(id, i);
    for(int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
