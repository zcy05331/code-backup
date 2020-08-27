#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

std::vector<int> vec;
int n, mina, flag, a[MaxN];

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

int main()
{   
    int T = read();
    while(T--)
    {
        vec.clear();
        n = read(), flag = 1, mina = 1e9 + 7;
        for(int i = 1; i <= n; i++)
            a[i] = read(), mina = std::min(mina, a[i]);
        for(int i = 1; i <= n; i++)
            if(a[i] % mina == 0)
                vec.push_back(a[i]), a[i] = 0;
        std::sort(vec.begin(), vec.end());
        for(int i = n; i; i--)
        {
            if(!a[i])
                a[i] = vec.back(), vec.pop_back();
        }
        for(int i = 1; i <= n; i++)
            if(a[i] < a[i - 1]) flag = 0;
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
