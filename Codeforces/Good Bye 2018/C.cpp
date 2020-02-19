#include <bits/stdc++.h>
#define ll long long
std::vector<ll> v, ans;
void prime(ll n)
{
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i * i != n)
            {
                v.push_back(n / i);
            }
        }
    }
}
std::map<ll, int> m;
int main()
{
    ll n;
    scanf("%I64d", &n);
    prime(n);
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]] = 1;
    }
    for(std::map<ll, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        ll x = n / it->first;
        ans.push_back((1 + (x * (it->first - 1) + 1)) * (it->first) / 2);
    }
    std::sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        printf("%I64d\n", ans[i]);
    return 0;
}