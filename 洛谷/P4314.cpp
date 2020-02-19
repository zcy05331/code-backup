#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)
#define checkmax(a, b) ((a) = ((a) < (b)) ? (b) : (a))

const int MaxN = 1e5 + 10;
const int inf = 0x3f3f3f3f;

struct node
{
    int l, r;
    int Max, Add, Set;
    int max, add, set;
};

int n, m, a[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    inline void pushup(int id)
    {
        t[id].max = std::max(t[id << 1].max, t[id << 1 | 1].max);
        t[id].Max = std::max(t[id << 1].Max, t[id << 1 | 1].Max);
    }
    inline void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r, t[id].set = t[id].Set = -inf;
        if (l == r)
        {
            t[id].max = t[id].Max = a[(l + r) >> 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        pushup(id);
    }
    inline void checksum(int id, int add, int Add)
    {
        if (t[id].set != -inf)
        {
            checkmax(t[id].Set, t[id].set + Add);
            checkmax(t[id].Max, t[id].max + Add);
            t[id].set += add, t[id].max += add;
        }
        else
        {
            checkmax(t[id].Add, t[id].add + Add);
            checkmax(t[id].Max, t[id].max + Add);
            t[id].add += add, t[id].max += add;
        }
    }
    inline void checkset(int id, int set, int Set)
    {
        checkmax(t[id].Set, Set);
        checkmax(t[id].Max, Set);
        t[id].set = set, t[id].max = set;
    }
    inline void pushdown(int id)
    {
        checksum(id << 1, t[id].add, t[id].Add), checksum(id << 1 | 1, t[id].add, t[id].Add), t[id].add = t[id].Add = 0;
        if (t[id].set != -inf)
        {
            checkset(id << 1, t[id].set, t[id].Set), checkset(id << 1 | 1, t[id].set, t[id].Set);
            t[id].set = t[id].Set = -inf;
        }
    }
    void add(int id, int l, int r, int val)
    {
        if (t[id].l > r || t[id].r < l)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            checksum(id, val, val);
            return;
        }
        pushdown(id), add(id << 1, l, r, val), add(id << 1 | 1, l, r, val), pushup(id);
    }
    void set(int id, int l, int r, int val)
    {
        if (t[id].l > r || t[id].r < l)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            checkset(id, val, val);
            return;
        }
        pushdown(id), set(id << 1, l, r, val), set(id << 1 | 1, l, r, val), pushup(id);
    }
    int query_max(int id, int l, int r)
    {
        if (t[id].l > r || t[id].r < l)
            return -inf;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].max;
        pushdown(id);
        return std::max(query_max(id << 1, l, r), query_max(id << 1 | 1, l, r));
    }
    int query_Max(int id, int l, int r)
    {
        if (t[id].l > r || t[id].r < l)
            return -inf;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].Max;
        pushdown(id);
        return std::max(query_Max(id << 1, l, r), query_Max(id << 1 | 1, l, r));
    }
} T;

char get()
{
    char ch = getchar();
    while (ch > 'Z' || ch < 'A')
        ch = getchar();
    return ch;
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

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    T.build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        char ch = get();
        int x = read(), y = read(), z;
        if (ch == 'Q')
            printf("%d\n", T.query_max(1, x, y));
        else if (ch == 'A')
            printf("%d\n", T.query_Max(1, x, y));
        else if (ch == 'P')
            z = read(), T.add(1, x, y, z);
        else
            z = read(), T.set(1, x, y, z);
    }
    return 0;
}
