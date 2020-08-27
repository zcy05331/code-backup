#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;
const int Max = MaxN * 40;

struct node
{
    int lc, rc, sum;
};

int n, m, q;
int a[MaxN], b[MaxN], root[MaxN];

struct SegmentTree
{
    int tot;
    node t[Max];
    void insert(int &rt, int pre, int l, int r, int pos)
    {
        rt = ++tot, t[rt].lc = t[pre].lc;
        t[rt].rc = t[pre].rc, t[rt].sum = t[pre].sum + 1;
        if(l == r) return;
        int mid = (l + r) >> 1;
        if(pos <= mid) insert(t[rt].lc, t[pre].lc, l, mid, pos);
        else insert(t[rt].rc, t[pre].rc, mid + 1, r, pos);
    }
    int query(int u, int v, int l, int r, int k)
    {
       if(l == r) return l;
       int mid = (l + r) >> 1, num = t[t[v].lc].sum - t[t[u].lc].sum;
       if(k <= num) return query(t[u].lc, t[v].lc, l, mid, k);
       else return query(t[u].rc, t[v].rc, mid + 1, r, k - num);
    }
} T;

void init()
{
    std::sort(b + 1, b + n + 1);
    m = std::unique(b + 1, b + n + 1) - b - 1;
    for(int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
}

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
    for(int i = 1; i <= n; i++)
        a[i] = b[i] = read();
    init();
    for(int i = 1; i <= n; i++)
        T.insert(root[i], root[i - 1], 1, m, a[i]);
    while(q--)
    {
        int l = read(), r = read(), k = read();
        printf("%d\n", b[T.query(root[l - 1], root[r], 1, m, k)]);
    }
    return 0;
}
