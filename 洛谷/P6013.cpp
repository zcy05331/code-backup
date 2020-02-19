#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

ll m, cnt, ans;
std::priority_queue<std::pair<ll, ll> > q;

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    m = read();
    for (int i = 1; i <= m; i++)
    {
        while (!q.empty() && -q.top().first <= i)
            cnt += q.top().second, q.pop();
        ll op = read(), a = read();
        if (op == 1)
            cnt += a;
        else if (op == 2)
        {
            if (cnt < a)
                ++ans;
            else
                cnt -= a;
        }
        else
        {
            ll b = read();
            q.push(std::make_pair(-b, a)), cnt -= a;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
