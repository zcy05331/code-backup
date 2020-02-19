#include <bits/stdc++.h>
#define getl(x) ((x - 1) * size + 1)
#define getr(x) std::min(n, getl(x + 1) - 1)
#define getblock(x) ((x - 1) / size + 1)

const int MaxN = 100010;

int n, size;
int a[MaxN], b[MaxN], add[MaxN];

inline void debug()
{
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i] + add[getblock(i)]);
    puts("");
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = 0;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

inline void init()
{
    int num = n / size;
    if (n % size)
        ++num;
    for (int i = 1; i <= num; i++)
    {
        int l = getl(i), r = getr(i);
        std::sort(b + l, b + r + 1);
    }
}

inline void modify(int l, int r, int x)
{
    int L = getblock(l), R = getblock(r);
    if (L == R)
    {
        for (int i = l; i <= r; i++)
            a[i] += x;
        for (int i = getl(L); i <= getr(R); i++)
            b[i] = a[i];
        std::sort(b + getl(L), b + getr(R) + 1);
        return;
    }
    for (int i = L + 1; i < R; i++)
        add[i] += x;
    for (int i = l; i <= getr(L); i++)
        a[i] += x;
    for (int i = getl(L); i <= getr(L); i++)
        b[i] = a[i];
    for (int i = getl(R); i <= r; i++)
        a[i] += x;
    for (int i = getl(R); i <= getr(R); i++)
        b[i] = a[i];
    std::sort(b + getl(L), b + getr(L) + 1);
    std::sort(b + getl(R), b + getr(R) + 1);
}

inline int query(int l, int r, int x)
{
    int ans = 0, L = getblock(l), R = getblock(r);
    if (L == R)
    {
        for (int i = l; i <= r; i++)
            if (a[i] + add[L] < x)
                ++ans;
        return ans;
    }
    for (int i = l; i <= getr(L); i++)
        if (a[i] + add[L] < x)
            ++ans;
    for (int i = getl(R); i <= r; i++)
        if (a[i] + add[R] < x)
            ++ans;
    for (int i = L + 1; i < R; i++)
    {
        int lpos = getl(i), rpos = getr(i), val = x - add[i] - 1;
        ans += std::upper_bound(b + lpos, b + rpos + 1, val) - b - lpos;
    }
    return ans;
}

signed main()
{
    n = read();
    size = sqrt(n) + 0.5;
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = a[i];
    init();
    for (int i = 1; i <= n; i++)
    {
        int op = read(), l = read(), r = read(), x = read();
        if (op == 0)
            modify(l, r, x);
        else
            printf("%d\n", query(l, r, x * x));
    }
    return 0;
}
