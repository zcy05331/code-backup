#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e3 + 10;

int n, m, q;

struct node
{
    int max, tag;
};

struct segmenttree
{
    node t[MaxN << 2];
    void modify(int id, int l, int r, int ql, int qr, int val)
    {
        if(l > qr || ql > r) return;
        t[id].max = std::max(t[id].max, val);
        if(ql <= l && r <= qr) 
            return (void) (t[id].tag = std::max(t[id].tag, val));
        int mid = (l + r) >> 1;
        modify(id << 1, l, mid, ql, qr, val);
        modify(id << 1 | 1, mid + 1, r, ql, qr, val);
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        if(l > qr || ql > r) return -1e9;
        if(ql <= l && r <= qr) return std::max(t[id].max, t[id].tag);
        int mid = (l + r) >> 1, tag = t[id].tag;
        return std::max(tag, std::max(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr)));
    }
}; 

struct SegmentTree
{
    segmenttree t[MaxN * 3], tag[MaxN * 3];
    int query(int id, int l, int r, int ql, int qr, int down, int up)
    {
        if(l > qr || ql > r) return -1e9;
        if(ql <= l && r <= qr) 
            return t[id].query(1, 1, m, down, up);
        int mid = (l + r) >> 1, Tag = tag[id].query(1, 1, m, down, up);
        return std::max(Tag, std::max(query(id << 1, l, mid, ql, qr, down, up), query(id << 1 | 1, mid + 1, r, ql, qr, down, up)));
    }
    void modify(int id, int l, int r, int ql, int qr, int down, int up, int val)
    {
        if(l > qr || ql > r) return;
        t[id].modify(1, 1, m, down, up, val);
        if(ql <= l && r <= qr) 
            return (void) tag[id].modify(1, 1, m, down, up, val);
        int mid = (l + r) >> 1;
        modify(id << 1, l, mid, ql, qr, down, up, val);
        modify(id << 1 | 1, mid + 1, r, ql, qr, down, up, val);
    }

} T;

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
    n = read(), m = read(), q = read();
    while(q--)
    {
        int d = read(), s = read(), h = read(), x = read() + 1, y = read() + 1;
        h += T.query(1, 1, n, x, x + d - 1, y, y + s - 1);
        T.modify(1, 1, n, x, x + d - 1, y, y + s - 1, h);
    }
    printf("%d\n", T.query(1, 1, n, 1, n, 1, m));
    return 0;
}
