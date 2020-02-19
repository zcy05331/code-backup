#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

std::priority_queue<std::pair<ll, ll> > q;

int main()
{   
    q.push(std::make_pair(1, 10)), q.push(std::make_pair(2, 5));
    printf("%lld\n", q.top().first);
    return 0;
}
