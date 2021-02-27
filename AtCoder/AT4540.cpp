#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 1e9 + 7;
const int MaxN = 1e4 + 10;

char s[MaxN];
ll n, d, num[MaxN], f[MaxN][101][2];

ll dfs(ll pos, ll now, ll up)
{
    if(pos == 0) return !now;
    if(~f[pos][now][up])
        return f[pos][now][up];
    ll ret = 0, max = (up ? num[pos] : 9);
    for(int i = 0; i <= max; i++)
        ret = sum(ret, dfs(pos - 1, (now + i) % d, up && (i == max)), mod);
    return f[pos][now][up] = ret;
}

int main()
{   
    memset(f, -1, sizeof(f));
    scanf("%s%lld", s + 1, &d), n = strlen(s + 1);
    for(int i = 1; i <= n; i++)
        num[i] = s[n - i + 1] - '0';
    printf("%lld\n", (dfs(n, 0, 1) + mod - 1) % mod);
    return 0;
}
