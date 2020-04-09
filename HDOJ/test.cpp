#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

int Rand()
{
    int x = rand(), y = rand();
    return x * 32768 + y;
}

int main()
{   
    int T = 100;
    srand(time(NULL));
    freopen("5306.in", "w", stdout);
    printf("%d\n", T);
    while(T--)
    {
        int n = 10000, m = 10000;
        printf("%d %d\n", n, m);
        for(int i = 1; i <= n; i++)
            printf("%d ", Rand());
        for(int i = 1; i <= m; i++)
        {
            int op, l, r;
            op = Rand(), l = Rand() % n + 1, r = Rand() % n + 1;
            if(l > r) std::swap(l, r);
            printf("%d %d %d ", op, l, r);
            if(op == 0) printf("%d\n", Rand());
            else printf("\n");
        }
    }
    return 0;
}
