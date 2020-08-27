#include <bits/stdc++.h>

#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;

struct node
{
    int ch[2];
    int size, cnt, val, rnd;
};

node t[MaxN << 5];
int n, m, tot, a[MaxN];

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
            x = ++tot, t[x].size = t[x].cnt = 1;
            t[x].rnd = rand(), t[x].val = val;
            return;
        }
        t[x].size++;
        if (t[x].val == val)
            return (void)(t[x].cnt++);
        int c = t[x].val < val;
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
                return (void)(t[x].size--, t[x].cnt--);
            int c = t[lc].rnd > t[rc].rnd;
            if (!lc || !rc)
                x = lc + rc;
            else
                rotate(x, c), del(x, val);
        }
        else
            t[x].size--, del(t[x].ch[t[x].val < val], val);
    }
    int query_rank(int x, int val)
    {
        if (!x) return 0;
        if (t[x].val == val)
            return t[lc].size;
        else if (val < t[x].val)
            return query_rank(lc, val);
        else
            return t[lc].size + t[x].cnt + query_rank(rc, val);
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
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
    }
    int query_rank(int id, int l, int r, int val)
    {
        if (l > tr[id].r || tr[id].l > r) return 0;
        if (l <= tr[id].l && tr[id].r <= r)
            return tr[id].query_rank(tr[id].root, val);
        int ans = 0;
        ans += query_rank(id << 1, l, r, val);
        ans += query_rank(id << 1 | 1, l, r, val);
        return ans;
    }
    int query_val(int l, int r, int val)
    {
        int L = 0, R = 1e9;
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
        if (pos < tr[id].l || tr[id].r < pos) return;
        tr[id].del(tr[id].root, a[pos]);
        tr[id].insert(tr[id].root, val);
        if (tr[id].l == tr[id].r) return;
        modify(id << 1, pos, val), modify(id << 1 | 1, pos, val);
    }
} T;

inline void write(int x)
{
    if (x < 0) x = ~x + 1, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

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
    freopen("P2617_11.in", "r", stdin);
    freopen("P2617.out", "w", stdout);
    char op[2];
    srand(19260817);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n);
    while (m--)
    {
        scanf("%s", op + 1);
        if (op[1] == 'Q')
        {
            int l = read(), r = read(), k = read();
            // write(T.query_val(l, r, k)), puts("");
            printf("%d\n", T.query_val(l, r, k));
        }
        else
        {
            int x = read(), y = read();
            T.modify(1, x, y), a[x] = y;
        }
    }
    std::cerr << clock();
    return 0;
}
