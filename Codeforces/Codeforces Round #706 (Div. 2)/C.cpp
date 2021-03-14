#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

int n;
std::vector<int> x, y;

int cmp(int a, int b) { return abs(a) < abs(b); }

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

signed main()
{   
    int T = read();
    while(T--)
    {
        n = read(), x.clear(), y.clear();
        for(int i = 1; i <= 2 * n; i++)
        {
            int a = read(), b = read();
            if(a == 0) y.push_back(b);
            else x.push_back(a);
        }
        std::sort(x.begin(), x.end(), cmp);
        std::sort(y.begin(), y.end(), cmp);
        double ans = 0;
        for(int i = 0; i < n; i++)
            ans += sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
        printf("%.15lf\n", ans);
    }
    return 0;
}
