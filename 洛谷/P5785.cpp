#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

ll n, s, l, r;
ll f[MaxN], q[MaxN], sumc[MaxN], sumt[MaxN];

ll Y(ll num) {return f[num];}
ll X(ll num) {return sumc[num];}
ll K(ll num) { return s + sumt[num]; }

int main()
{   
    scanf("%lld%lld", &n, &s);
    for(int i = 1; i <= n; i++)
    {
        int c, t;
        scanf("%d%d", &t, &c);
        sumt[i] = sumt[i - 1] + t;
        sumc[i] = sumc[i - 1] + c;
    }
    l = r = 1, q[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        while(l < r && (Y(q[l + 1]) - Y(q[l])) <= K(i) * (X(q[l + 1]) - X(q[l]))) ++l;
        f[i] = f[q[l]] - (s + sumt[i]) * sumc[q[l]] + sumt[i] * sumc[i] + s * sumc[n];
        while(l < r && (Y(q[r]) - Y(q[r - 1])) * (X(i) - X(q[r])) >= (Y(i) - Y(q[r])) * (X(q[r]) - X(q[r - 1]))) --r;
        q[++r] = i; 
    }
    printf("%lld\n", f[n]);
    return 0;
}
