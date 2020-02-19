#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

std::map<int, int> m;

int f(int x)
{
    x += 1;
    while (x % 10 == 0)
        x /= 10;
    return x;
}

int main()
{
    int x;
    scanf("%d", &x);
    m[x] = 1;
    while (!m[f(x)])
        x = f(x), m[x] = 1;
    printf("%d\n", m.size());
    return 0;
}
