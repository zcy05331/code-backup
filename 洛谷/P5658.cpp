#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

char ch[MaxN];
ll n, ans[MaxN], f[MaxN], last[MaxN], cnt[MaxN];

int main()
{
    scanf("%lld%s", &n, ch + 1);
    for (int i = 2; i <= n; i++)
        scanf("%lld", &f[i]);
    ll Ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ch[i] == '(')
        {
            cnt[i] = 0;
            last[i] = i;
        }
        else
        {
            last[i] = last[f[i]];
            cnt[i] = (last[i] ? (cnt[f[last[i]]] + 1) : 0);
            last[i] = ((last[f[i]]) ? last[f[last[f[i]]]] : 0);
            // printf("%d %d %d\n", i, last[i], cnt[i]);
        }
        ans[i] = (cnt[i] + ans[f[i]]);
        Ans ^= (ans[i] * i);
    }
    printf("%lld\n", Ans);
    return 0;
}
