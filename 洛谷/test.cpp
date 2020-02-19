#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

char s[MaxN];
unsigned ll n, pos, L;
unsigned ans, cnt[200];

int main()
{
    scanf("%s%llu", s + 1, &L), n = strlen(s + 1);
    for (R unsigned i = 1; i <= n; ++i)
        if (++cnt[s[i]] > cnt[pos])
            pos = s[i];
    pos = cnt[pos];
    while (n < L - pos)
    {
        if (pos == (1ll << 31))
            break;
        n += pos, pos <<= 1ll, ++ans;
    }
    printf("%u\n", ans + 1);
    return 0;
}
