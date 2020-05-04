#include <bits/stdc++.h>

#define ll long long
#define pir std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, q, cnt;

struct BIT
{
    int c[MaxN];
    int lowbit(int x) {return x & (-x); }
    void add(int x)
    {
        while(x <= n)
            c[x]++, x += lowbit(x);
    }
    int query(int x)
    {
        int ret = 0;
        while(x)
            ret += c[x], x -= lowbit(x);
        return ret;
    }
    int Query(int l, int r) { return query(r) - query(l - 1);}
}L, R;

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
    n = read(), q = read();
    for(int i = 1; i <= q; i++)
    {
        int op = read(), l = read(), r = read();
        if(op == 1)
            ++cnt, L.add(l), R.add(r);
        else
        {
            int a1 = std::max(0, R.Query(r, n) - L.Query(1, l - 1));
            int a2 = std::max(0, L.Query(1, r) - R.Query(r + 1, n));
            printf("%d\n", a1 + a2 - cnt);
        }

    }
    return 0;
}
