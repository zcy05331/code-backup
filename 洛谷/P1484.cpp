#include <bits/stdc++.h>
#define ll long long
const int MaxN = 500010;
struct node
{
    ll val, pos;
    bool operator<(const node &a) const
    {
        return val < a.val;
    }
};
node tmp;
bool vis[MaxN];
ll n, m, ans;
ll l[MaxN], r[MaxN], a[MaxN];
std::priority_queue<node> pq;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &tmp.val);
        a[i] = tmp.val;
        tmp.pos = i, l[i] = i - 1, r[i] = i + 1;
        pq.push(tmp);
    }
    r[0] = 1, l[n + 1] = n;
    while (m--)
    {
        while (vis[pq.top().pos])
            pq.pop();
        tmp = pq.top();
        pq.pop();
        if (tmp.val < 0)
            break;
        ans += tmp.val;
        int id = tmp.pos;
        a[id] = a[l[id]] + a[r[id]] - a[id];
        tmp.val = a[id];
        vis[l[id]] = vis[r[id]] = 1;
        l[id] = l[l[id]], r[l[id]] = id;
        r[id] = r[r[id]], l[r[id]] = id;
        pq.push(tmp);
    }
    printf("%lld\n", ans);
    return 0;
}
