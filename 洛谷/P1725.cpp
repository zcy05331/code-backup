#include <bits/stdc++.h>
const int MaxN = 200010;
int now;
int n, l, r;
int a[MaxN], f[MaxN];
std::deque<int> dq;
void init(int x)
{
    while (!dq.empty() && dq.front() < x - r)
        dq.pop_front();
    for (; now <= x - l; ++now)
    {
        while (!dq.empty() && f[dq.back()] <= f[now])
            dq.pop_back();
        dq.push_back(now);
    }
}
int main()
{
    int ans = 0;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = l; i <= n; i++)
    {
        init(i);
        if(!dq.empty())
            f[i] = a[i] + f[dq.front()];
        else f[i] = a[i];
    }
    
    for(int i = 1; i <= n; i++)ans = std::max(ans, f[i]);
    printf("%d", ans);
    return 0;
}