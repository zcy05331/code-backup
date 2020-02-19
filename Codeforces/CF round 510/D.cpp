#include <bits/stdc++.h>

#define lowbit(x) (x & (-x))

const int MaxN = 200010;

int n;
int cnt;
long long t;
int c[MaxN << 2];
long long a[MaxN], s[MaxN];
std::map<long long, int>m;

int query(int x)
{
    int ans = 0;
    while(x)
        ans += c[x], x -= lowbit(x);
    return ans;
}

void add(int x, int val)
{
    while(x <= cnt)
        c[x] += val, x += lowbit(x);
}

int main()
{
    scanf("%d%lld", &n, &t);
    m[-t] = m[0] = 1;
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i], m[s[i] - t] = m[s[i]] = 1;
    for(std::map<long long, int>::iterator it = m.begin(); it != m.end(); it++)
        it -> second = ++cnt;
    long long ans = 0;
    add(m[0], 1);
    for(int i = 1; i <= n; i++)
    {
        ans += i - query(m[s[i] - t]);
        add(m[s[i]], 1);
    }
    printf("%lld", ans);
    return 0;
}