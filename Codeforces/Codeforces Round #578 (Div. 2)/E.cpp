#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;
const ll mod = 998244353;

int n, base;
ll h[MaxN << 4], len[MaxN];
std::string s[MaxN], t;

ll fast_pow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

ll get(ll l, ll r) { return ((h[r] - h[l - 1] * fast_pow(base, r - l + 1)) % mod + mod) % mod; }

int main()
{
    srand(time(NULL));
    scanf("%d", &n);
    base = rand() % 1000 + 233;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i], len[i] = s[i].length();
    for (int i = 1; i <= len[1]; i++)
        h[i] = (h[i - 1] * base + s[1][i - 1]) % mod, t += s[1][i - 1];
    int now = len[1] + 1;
    for (int i = 2; i <= n; i++)
    {
        ll has = 0, pos = -1;
        for (int j = 0; j < len[i]; j++)
        {
            has = (has * base + s[i][j]) % mod;
            if (j >= now)
                break;
            //printf("%d %d\n", has, get(now - j - 1, now - 1));
            if (has == get(now - j - 1, now - 1))
                pos = j;
        }
        for (int j = pos + 1; j < len[i]; j++)
            h[now] = (h[now - 1] * base + s[i][j]) % mod, ++now, t += s[i][j];
    }
    std::cout << t;
    return 0;
}
