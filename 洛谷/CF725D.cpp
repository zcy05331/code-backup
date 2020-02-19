#include <bits/stdc++.h>
const int MaxN = 300010;
struct team
{
    long long t, w;
    int operator<(team b) const
    {
        return w - t > b.w - b.t;
    }
};
team t[MaxN];
int cmp1(team a, team b) { return a.t > b.t; }
inline long long read()
{
    long long x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}
std::priority_queue<team> pq;
int main()
{
    register int n;
    register int pop = 0;
    register int cur = 1;
    register int ans = MaxN;
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++)
        t[i].t = read(), t[i].w = read();
    std::sort(t + 2, t + n + 1, cmp1);
    for (register int i = 2; i <= n; i++)
        if (t[i].t > t[1].t)
            pq.push(t[i]), ++cur;
        else
            break;
    ans = cur;
    while (!pq.empty())
    {
        if (t[1].t > pq.top().w - pq.top().t)
        {
            t[1].t -= (pq.top().w - pq.top().t + 1);
            pq.pop();
            ++pop;
            for (register int i = cur + 1; i <= n; ++i)
                if (t[i].t > t[1].t)
                    ++cur, pq.push(t[i]);
                else break;
            ans = std::min(ans, cur - pop);
        }
        else
            break;
    }
    printf("%d\n", ans);
    return 0;
}