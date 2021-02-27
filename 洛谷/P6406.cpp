#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define mul(a, b, mod) (((a) * (b)) % mod)
#define sum(a, b, mod) (((a) + (b)) % mod)
#define S(l, r) ((((l) + (r)) * ((r) - (l) + 1) / 2) % mod)

const ll mod = 1e9;
const ll MaxN = 5e5 + 10;

ll n, ans, a[MaxN], max[MaxN], min[MaxN], s[4][MaxN];
 
void Add(ll &a, ll b) { a = sum(a, b, mod); }
ll get(ll s[], ll l, ll r) { return (s[r] - s[l - 1] + mod) % mod; }

void solve(ll l, ll r)
{
    if(l == r) return Add(ans, a[l] * a[l]);
    int mid = (l + r) >> 1;
    solve(l, mid), solve(mid + 1, r);
    ll p = 0, q = 0, mn = 1e8, mx = 0;
    max[mid] = min[mid] = s[0][mid] = 0;
    s[1][mid] = s[2][mid] = s[3][mid] = 0;
    for(int i = mid + 1; i <= r; i++)
    {
        mn = std::min(a[i], mn), mx = std::max(a[i], mx);
        min[i] = min[i - 1] + mn, max[i] = max[i - 1] + mx;
        s[0][i] = sum(s[0][i - 1], mn * i, mod);
        s[1][i] = sum(s[1][i - 1], mx * i, mod);
        s[2][i] = sum(s[2][i - 1], mn * mx, mod);
        s[3][i] = sum(s[3][i - 1], mn * mx % mod * i, mod);
    }
    mn = 1e9, mx = 0, p = q = mid + 1;
    for(int i = mid; i >= l; i--)
    {
        mn = std::min(a[i], mn), mx = std::max(a[i], mx);
        while(p <= r && a[p] > mn) ++p;
        while(q <= r && a[q] < mx) ++q;
        if(p < q)
        {
            Add(ans, mn * mx % mod * S(mid - i + 2, p - i));
            Add(ans, mx * get(s[0], p, q - 1) % mod +  
                mx * (mod - i + 1) % mod * get(min, p, q - 1));
            Add(ans, get(s[3], q, r) + (mod - i + 1) * get(s[2], q, r));
        }
        else
        {
            Add(ans, mn * mx % mod * S(mid - i + 2, q - i));
            Add(ans, mn * get(s[1], q, p - 1) % mod +
                mn * (mod - i + 1) % mod * get(max, q, p - 1));
            Add(ans, get(s[3], p, r) + (mod - i + 1) * get(s[2], p, r));
        }
    }
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
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    solve(1, n), printf("%lld\n", ans);
    return 0;
}
