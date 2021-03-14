#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 1e3 + 10;

int n, k, f[MaxN];
std::vector<int> v;

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{   
    int T = read();
    while(T--)
    {
        memset(f, 0, sizeof(f));
        n = read(), k = read(), v.clear();
        for(int i = 1; i <= n; i++)
            if(i > k) v.push_back(i);
        f[0] = 1;
        for(int i = k - 1; i; i--)
        {
            if(!f[k - i])
            {
                v.push_back(i);
                for(int j = k; j >= i; j--)
                    f[j] |= f[j - i];
            }
        }
        printf("%d\n", v.size());
        for(auto x : v) printf("%d ", x);
        puts("");
    }
    return 0;
}
