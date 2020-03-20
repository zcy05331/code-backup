#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct node
{
    int id, tim;
    bool operator<(node x) const { return tim > x.tim; }
};

int n, m, k, p;
std::priority_queue<node> q;
ll h[MaxN], a[MaxN], cnt[MaxN];

bool check(ll mid)
{
    while (!q.empty())
        q.pop();
    memset(cnt, 0, sizeof(cnt));
    for (R int i = 1; i <= n; i++)
        if (mid - m * a[i] < h[i])
            q.push({i, mid / a[i]});
    for (R int i = 1; q.size() && i <= m; i++)
    {
        node now;
        for (R int j = 1; j <= k && q.size(); j++)
        {
            now = q.top(), q.pop(), ++cnt[now.id];
            if (now.tim < i) return 0;
            if (mid + cnt[now.id] * p - m * a[now.id] < h[now.id])
                q.push({now.id, (mid + cnt[now.id] * p) / a[now.id]});
        }
    }
    return q.empty();
}

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
    n = read(), m = read();
    k = read(), p = read();
    ll l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        h[i] = read(), a[i] = read();
        r = std::max(r, h[i] + a[i] * m);
    }
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld", l);
    return 0;
}