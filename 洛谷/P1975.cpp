#include <bits/stdc++.h>

#define R register
#define ll long long
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define meow(cat...) fprintf(stderr, cat)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;
const int Max = MaxN << 5;

struct node
{
    int ch[2];
    int size, rnd, val, cnt;
};

node t[Max];
int n, q, cnt, ans, a[MaxN];

struct treap
{
    int l, r, rt;
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
            x = ++cnt, t[x].cnt = t[x].size = 1;
            t[x].val = val, t[x].rnd = rand();
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
    void remove(int &x, int val)
    {
        if (!x) return;
        if (t[x].val == val)
        {
            if (t[x].cnt > 1)
                return (void)(t[x].cnt--, t[x].size--);
            int c = t[lc].rnd > t[rc].rnd;
            if (!lc || !rc)
                x = lc + rc;
            else
                rotate(x, c), remove(x, val);
        }
        else
            t[x].size--, remove(t[x].ch[val > t[x].val], val);
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
};

struct SegmentTree
{
    treap t[MaxN];
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        for (int i = l; i <= r; i++)
            t[id].insert(t[id].rt, a[i]);
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    void modify(int id, int pos, int val)
    {
        if (t[id].l > pos || pos > t[id].r)
            return;
        t[id].remove(t[id].rt, a[pos]);
        t[id].insert(t[id].rt, val);
        if (t[id].l == t[id].r) return;
        modify(id << 1, pos, val), modify(id << 1 | 1, pos, val);
    }
    int query_rank(int id, int l, int r, int val)
    {
        if (t[id].l > r || l > t[id].r || l > r) return 0;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].query_rank(t[id].rt, val);
        int ans = 0;
        ans += query_rank(id << 1, l, r, val);
        ans += query_rank(id << 1 | 1, l, r, val);
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

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n);
    for (int i = 1; i < n; i++)
        ans += T.query_rank(1, i + 1, n, a[i]);
    printf("%d\n", ans), q = read();
    while (q--)
    {
        int l = read(), r = read(), len = r - l - 1;
        if(l > r) std::swap(l, r);
        if (a[l] == a[r])
        {
            printf("%d\n", ans);
            continue;
        }
        ans -= T.query_rank(1, l + 1, r - 1, a[l]);
        ans -= len - T.query_rank(1, l + 1, r - 1, a[r] + 1);
        T.modify(1, l, a[r]), T.modify(1, r, a[l]), std::swap(a[l], a[r]);
        ans += T.query_rank(1, l + 1, r - 1, a[l]);
        ans += len - T.query_rank(1, l + 1, r - 1, a[r] + 1);
        ((a[l] > a[r]) ? ++ans : --ans), printf("%d\n", ans);
    }
    return 0;
}
