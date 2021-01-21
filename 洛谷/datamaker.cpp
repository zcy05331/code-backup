#include <bits/stdc++.h>

#define R register
#define ll long long
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, m, a[MaxN];

signed main()
{   
    srand(time(NULL));
    freopen("sqrt.in", "w", stdout);
    n = 100000, m = 100000, printf("%d %d\n", n, m);
    for(int i = 1; i <= n; i++) a[i] = i;
    std::random_shuffle(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) 
        printf("%d%c", a[i], " \n"[i == n]);
    for(int i = 1; i <= m; i++)
    {
        int l = rand() % n + 1, r = rand() % n + 1;
        printf("%d %d\n", std::min(l, r), std::max(l, r));
    }
    return 0;
}
