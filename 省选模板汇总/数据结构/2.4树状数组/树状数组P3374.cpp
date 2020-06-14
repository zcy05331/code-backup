#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 +10;

int n, m, a[MaxN];

struct BIT
{
    int c[MaxN];
    int lowbit(int x) { return x & (-x); }
    void add(int pos, int val)
    {
        while(pos <= n)
            c[pos] += val, pos += lowbit(pos);
    }
    int query(int pos)
    {
        int ret = 0;
        while(pos)
            ret += c[pos], pos -= lowbit(pos);
        return ret;
    }
    int Query(int l, int r) {return query(r) - query(l - 1); }
}T;

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

int main()
{   
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read(), T.add(i, a[i]);
    while(m--)
    {
        int op = read(), x = read(), y = read();
        if(op == 1)
            T.add(x, y);
        else printf("%d\n", T.Query(x, y));
    }
    return 0;
}
