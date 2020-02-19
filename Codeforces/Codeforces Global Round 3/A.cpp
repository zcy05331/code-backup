#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int main()
{
    ll a, b, c;
    std::cin >> a >> b >> c;
    if (a != b)
        std::cout << (c * 2 + std::min(a, b) * 2 + 1);
    else
        std::cout << (c * 2 + std::min(a, b) * 2);
    return 0;
}
