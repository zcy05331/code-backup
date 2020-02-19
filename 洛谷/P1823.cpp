#include <bits/stdc++.h>
const int MaxN = 500010;
std::stack<std::pair<int, int> > s;
int main()
{
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int h;
        scanf("%d", &h);
        std::pair<int, int> p = std::make_pair(h, 1);
        while(!s.empty() && s.top().first <= h)
        {
            ans += s.top().second;
            if(s.top().first == h)
                p.second += s.top().second;
            s.pop();
        }
        if(!s.empty())
            ++ans;
        s.push(p);
    }
    printf("%lld", ans);
    return 0;
}