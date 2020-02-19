#include <bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
ll ans[4], s;
int c[20];
inline ll calc(ll x)
{
    if (x <= 0)
        return 0;
    reg ll t = x;
    reg int len = 0;
    while (t)
        c[++len] = t % 10, t /= 10;
    ans[0] = ans[1] = ans[2] = ans[3] = s = 0;
    for (reg int i = len; i; i--)
    {
        ans[3] += ans[2] * 9;
        ans[2] += ans[1] * 9;
        ans[1] += ans[0] * 9;
        if (c[i])
        {
            if (s <= 3)
                ans[s]++, ans[s + 1] += c[i] - 1;
            s++;
        }
    }
    return ans[1] + ans[2] + ans[3] + (s <= 3);
}
int main()
{
    reg int T;
    scanf("%d", &T);
    while (T--)
    {
        static ll l, r;
        scanf("%I64d%I64d", &l, &r);
        printf("%I64d\n", calc(r) - calc(l - 1));
    }
    return 0;
}