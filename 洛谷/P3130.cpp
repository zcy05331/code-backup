#prag\
ma G++ optimize("Ofast")
#include <bits/stdc++.h>

const int MaxN = 200010;
const long long inf = 0x7fffffffffffffff;
struct node
{
    int l, r;
    long long add, mul;
    long long sum, max, min;
};

long long x[MaxN];
node t[MaxN << 2];

inline void pushup(int id)
{
    t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
    t[id].max = std::max(t[id << 1].max, t[id << 1 | 1].max);
    t[id].min = std::min(t[id << 1].min, t[id << 1 | 1].min);
}

inline void build(int id, int l, int r)
{
    t[id].mul = 1;
    t[id].l = l, t[id].r = r;
    if (l == r)
    {
        t[id].max = t[id].min = t[id].sum = x[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushup(id);
}

inline int pushdown(int id)
{
    int ls = id << 1, rs = id << 1 | 1;
    t[ls].sum = t[ls].sum * t[id].mul + t[id].add * (t[ls].r - t[ls].l + 1);
    t[rs].sum = t[rs].sum * t[id].mul + t[id].add * (t[rs].r - t[rs].l + 1);
    t[ls].max = t[ls].max * t[id].mul + t[id].add;
    t[rs].max = t[rs].max * t[id].mul + t[id].add;
    t[ls].min = t[ls].min * t[id].mul + t[id].add;
    t[rs].min = t[rs].min * t[id].mul + t[id].add;
    t[ls].mul *= t[id].mul, t[rs].mul *= t[id].mul;
    t[ls].add *= t[id].mul, t[rs].add *= t[id].mul;
    t[ls].add += t[id].add, t[rs].add += t[id].add;
    t[id].add = 0, t[id].mul = 1;
}

inline void add(int id, int l, int r, long long delta)
{
    if (r < t[id].l || t[id].r < l)
        return;
    if (l <= t[id].l && t[id].r <= r)
    {
        t[id].max += delta;
        t[id].min += delta;
        t[id].sum += delta * (t[id].r - t[id].l + 1);
        t[id].add += delta;
        return;
    }
    if (t[id].l == t[id].r)
        return;
    pushdown(id);
    add(id << 1, l, r, delta), add(id << 1 | 1, l, r, delta);
    pushup(id);
}

inline void mul(int id, int l, int r, long long delta)
{
    if (r < t[id].l || t[id].r < l)
        return;
    if (l <= t[id].l && t[id].r <= r)
    {
        t[id].max *= delta;
        t[id].min *= delta;
        t[id].sum *= delta;
        t[id].add *= delta;
        t[id].mul *= delta;
        return;
    }
    if (t[id].l == t[id].r)
        return;
    pushdown(id);
    mul(id << 1, l, r, delta), mul(id << 1 | 1, l, r, delta);
    pushup(id);
}

inline long long query_sum(int id, int l, int r)
{
    if (r < t[id].l || t[id].r < l)
        return 0;
    if (l <= t[id].l && t[id].r <= r)
        return t[id].sum;
    if (t[id].l == t[id].r)
        return 0;
    pushdown(id);
    return query_sum(id << 1, l, r) + query_sum(id << 1 | 1, l, r);
}

long long query_min(int id, int l, int r)
{
    if (r < t[id].l || t[id].r < l)
        return inf;
    if (l <= t[id].l && t[id].r <= r)
        return t[id].min;
    if (t[id].l == t[id].r)
        return inf;
    pushdown(id);
    return std::min(query_min(id << 1, l, r), query_min(id << 1 | 1, l, r));
}

inline long long query_max(int id, int l, int r)
{
    if (r < t[id].l || t[id].r < l)
        return -inf;
    if (l <= t[id].l && t[id].r <= r)
        return t[id].max;
    if (t[id].l == t[id].r)
        return -inf;
    pushdown(id);
    return std::max(query_max(id << 1, l, r), query_max(id << 1 | 1, l, r));
}

int main()
{
    register int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &x[i]);
    build(1, 1, n);
    for (register int i = 1; i <= m; ++i)
    {
        register int l, r;
        register long long a;
        std::string op;
        std::cin >> op;
        scanf("%d%d", &l, &r);
        if(op == "M")
            printf("%lld\n", query_min(1, l, r));
        else if(op == "S")
            printf("%lld\n", query_sum(1, l, r));
        else scanf("%lld", &a), add(1, l, r, a);
    }
    return 0;
}