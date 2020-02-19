#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int main()
{   
    std::map<int, int> m;
    m[2] = 2;
    std::map<int, int>::iterator it = m.end();
    --it;
    printf("%d\n", it->first);
    --it->second;
    printf("%d\n", m[2]);
    return 0;
}
