#include <bits/stdc++.h>
#define ll long long
#define getl(x) ((x - 1) * size + 1)
#define getr(x) std::min(n, getl(x + 1) - 1)
#define getblock(x) ((x - 1) / size + 1)

const int MaxN = 100010;

int n, size;
int a[MaxN], add[MaxN];

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

inline void modify(int l, int r, int x)
{
    int L = getblock(l), R = getblock(r);
    if(L == R)
    {
        for(int i = l; i <= r; i++)
            a[i] += x;
        return;
    }
    for(int i = L + 1; i < R; i++)
        add[i] += x;
    for(int i = l; i <= getr(L); i++)
        a[i] += x;
    for(int i = getl(R); i <= r; i++)
        a[i] += x;
}

inline int query(int r){return a[r] + add[getblock(r)];}

int main()
{   
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    size = sqrt(n) + 0.5;
    for(int i = 1; i <= n; i++)
    {
        int op = read(), l = read(), r = read(), x = read();
        if(op == 0)
            modify(l, r, x);
        else 
            printf("%d\n", query(r));
    }
    return 0;
}
