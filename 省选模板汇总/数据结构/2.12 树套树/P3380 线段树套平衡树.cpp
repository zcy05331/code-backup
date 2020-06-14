#include <bits/stdc++.h>

#define ll long long
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;
const int inf = 2147483647;

int n, m, tot, a[MaxN];

struct node
{
    int ch[2];
    int cnt, size, val, rnd;
};
node t[MaxN << 5];

struct treap
{
    int l, r, root;
    void update(int x) { t[x].size = t[lc].size + t[rc].size + t[x].cnt; }
    void rotate(int &x, int c)
    {
        int y = t[x].ch[c];
        t[x].ch[c] = t[y].ch[c ^ 1];
        t[y].ch[c ^ 1] = x, update(x), update(x = y);
    }
    void insert(int &x, int val)
    {
        if (!x)
        {
            x = ++tot, t[x].cnt = t[x].size = 1;
            t[x].rnd = rand(), t[x].val = val;
            return;
        }
        t[x].size++;
        if (t[x].val == val)
            return (void)(++t[x].cnt);
        int c = val > t[x].val;
        insert(t[x].ch[c], val);
        if (t[x].rnd > t[t[x].ch[c]].rnd)
            rotate(x, c);
    }
    void del(int &x, int val)
    {
        if (!x) return;
        if (t[x].val == val)
        {
            if (t[x].cnt > 1)
                return (void)(--t[x].cnt, --t[x].size);
            int c = t[lc].rnd > t[rc].rnd;
            if (!lc || !rc)
                x = lc + rc;
            else
                rotate(x, c), del(x, val);
        }
        else
            --t[x].size, del(t[x].ch[t[x].val < val], val);
    }
    int query_rank(int x, int val)
    {
        if (!x) return 0;
        if (t[x].val == val)
            return t[lc].size;
        if (t[x].val > val)
            return query_rank(lc, val);
        else
            return t[lc].size + t[x].cnt + query_rank(rc, val);
    }
    int query_val(int x, int val)
    {
        if (!x) return 0;
        if (val <= t[lc].size)
            return query_val(lc, val);
        else if (val > t[lc].size + t[x].cnt)
            return query_val(rc, val - t[lc].size - t[x].cnt);
        else
            return t[x].val;
    }
    int query_pre(int x, int val)
    {
        if (!x) return -inf;
        if (t[x].val >= val)
            return query_pre(lc, val);
        else
            return std::max(t[x].val, query_pre(rc, val));
    }
    int query_sub(int x, int val)
    {
        if (!x) return inf;
        if (t[x].val <= val)
            return query_sub(rc, val);
        else
            return std::min(t[x].val, query_sub(lc, val));
    }
};

treap tr[MaxN << 2];

struct SegmentTree
{
    void build(int id, int l, int r)
    {
        tr[id].l = l, tr[id].r = r;
        for (int i = l; i <= r; i++)
            tr[id].insert(tr[id].root, a[i]);
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    int query_rank(int id, int l, int r, int val)
    {
        if (tr[id].l > r || tr[id].r < l) return 0;
        if (l <= tr[id].l && tr[id].r <= r)
            return tr[id].query_rank(tr[id].root, val);
        int ans = 0;
        ans += query_rank(id << 1, l, r, val);
        ans += query_rank(id << 1 | 1, l, r, val);
        return ans;
    }
    int query_val(int l, int r, int val)
    {
        int L = 0, R = 1e8;
        while (L < R)
        {
            int mid = (L + R + 1) >> 1;
            if (query_rank(1, l, r, mid) + 1 <= val)
                L = mid;
            else
                R = mid - 1;
        }
        return L;
    }
    void modify(int id, int pos, int val)
    {
        if (tr[id].l > pos || pos > tr[id].r)
            return;
        tr[id].del(tr[id].root, a[pos]);
        tr[id].insert(tr[id].root, val);
        if (tr[id].l == tr[id].r) return;
        modify(id << 1, pos, val), modify(id << 1 | 1, pos, val);
    }
    int query_pre(int id, int l, int r, int val)
    {
        if (tr[id].l > r || tr[id].r < l) return -inf;
        if (l <= tr[id].l && tr[id].r <= r)
            return tr[id].query_pre(tr[id].root, val);
        int ans = std::max(query_pre(id << 1, l, r, val), query_pre(id << 1 | 1, l, r, val));
        return ans;
    }
    int query_sub(int id, int l, int r, int val)
    {
        if (tr[id].l > r || tr[id].r < l) return inf;
        if (l <= tr[id].l && tr[id].r <= r)
            return tr[id].query_sub(tr[id].root, val);
        int ans = std::min(query_sub(id << 1, l, r, val), query_sub(id << 1 | 1, l, r, val));
        return ans;
    }
} T;

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    srand(19260817);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n);
    while (m--)
    {
        int op = read(), l, r, val, pos;
        if (op == 3)
        {
            pos = read(), val = read();
            T.modify(1, pos, val), a[pos] = val;
            continue;
        }
        l = read(), r = read(), val = read();
        if (op == 1)
            printf("%d\n", T.query_rank(1, l, r, val) + 1);
        else if (op == 2)
            printf("%d\n", T.query_val(l, r, val));
        else if (op == 4)
            printf("%d\n", T.query_pre(1, l, r, val));
        else if (op == 5)
            printf("%d\n", T.query_sub(1, l, r, val));
    }
    return 0;
}
