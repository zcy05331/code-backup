#include <bits/stdc++.h>
#define lson (id << 2)
#define rson ((id << 2) | 1)
#define update(id) t[id].sum = (t[lson].sum + t[rson].sum) % p;

struct node
{
    int l, r;
    long long add, mul;
    long long sum;
};

const int MaxN = 100010;
long long n, p, m;
long long x[MaxN];
node t[MaxN << 2];

void build(int id, int l, int r)
{
    t[id].l = l;
    t[id].r = r;
    t[id].mul = 1;
    if(l == r)
    {
        t[id].sum = x[l] % p;
        return;
    }
    long long mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    update(id);
}

void pushdown(int id)
{

}

void add(int id, int l, int r, int delta)
{

}

void mul(int id, int l, int r, int delta)
{

}

long long main()
{
    scanf("%d%d", &n, &p);
    for(long long i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    build(1, 1, n);
    scanf("%lld", &m);
    
    return 0;
}