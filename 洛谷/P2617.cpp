#include <bits/stdc++.h>
#define reg register
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
using namespace std;
const int MaxN = 50010;
const int inf = 2147483647;
int n, m, tot;
int a[MaxN];
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
        int s = t[x].ch[c];
        t[x].ch[c] = t[s].ch[c ^ 1];
        t[s].ch[c ^ 1] = x;
        update(x);
        update(x = s);
    }
    void insert(int &x, int val)
    {
        if (!x)
        {
            x = ++tot;
            t[x].cnt = t[x].size = 1;
            t[x].rnd = rand(), t[x].val = val;
            return;
        }
        t[x].size++;
        if (t[x].val == val)
        {
            ++t[x].cnt;
            return;
        }
        int c = val > t[x].val;
        insert(t[x].ch[c], val);
        if (t[x].rnd > t[t[x].ch[c]].rnd)
            rotate(x, c);
    }
    void del(int &x, int val)
    {
        if (!x)
            return;
        if (t[x].val == val)
        {
            if (t[x].cnt > 1)
            {
                t[x].cnt--, t[x].size--;
                return;
            }
            bool c = t[lc].rnd > t[rc].rnd;
            if (lc == 0 || rc == 0)
                x = lc + rc;
            else
                rotate(x, c), del(x, val);
        }
        else
            --t[x].size, del(t[x].ch[t[x].val < val], val);
    }
    int rank(int x, int val)
    {
        if (!x)
            return 0;
        if (t[x].val == val)
            return t[lc].size;
        if (t[x].val > val)
            return rank(lc, val);
        else
            return t[lc].size + t[x].cnt + rank(rc, val);
    }
    int query_val(int x, int val)
    {
        while (1)
        {
            if (val <= t[lc].size)
                x = lc;
            else if (val > t[lc].size + t[x].cnt)
                val -= t[lc].size + t[x].cnt, x = rc;
            else
                return t[x].val;
        }
    }
    int query_pre(int x, int val)
    {
        if (!x)
            return -inf;
        if (t[x].val >= val)
            return query_pre(lc, val);
        else
            return cmax(t[x].val, query_pre(rc, val));
    }
    int query_sub(int x, int val)
    {
        if (!x)
            return inf;
        if (t[x].val <= val)
            return query_sub(rc, val);
        else
            return cmin(t[x].val, query_sub(lc, val));
    }
};
struct tree
{
    treap t[MaxN << 2];
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        for (int i = l; i <= r; i++)
            t[id].insert(t[id].root, a[i]);
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    int query_rank(int id, int l, int r, int val)
    {
        if (t[id].l > r || t[id].r < l)
            return 0;
        if (l <= t[id].l && t[id].r <= r)
        {
            int ans = t[id].rank(t[id].root, val);
            return ans;
        }
        int ans = 0;
        ans += query_rank(id << 1, l, r, val);
        ans += query_rank(id << 1 | 1, l, r, val);
        return ans;
    }
    int query_val(int l, int r, int k)
    {
        int L = 0, R = 1e8;
        while (L < R)
        {
            int mid = (L + R + 1) >> 1;
            if (query_rank(1, l, r, mid) + 1 <= k)
                L = mid;
            else
                R = mid - 1;
        }
        return L;
    }
    void modify(int id, int pos, int val)
    {
        if (pos < t[id].l || t[id].r < pos)
            return;
        t[id].del(t[id].root, a[pos]);
        t[id].insert(t[id].root, val);
        if (t[id].l == t[id].r)
            return;
        modify(id << 1, pos, val);
        modify(id << 1 | 1, pos, val);
    }
    int query_pre(int id, int l, int r, int val)
    {
        if (t[id].l > r || t[id].r < l)
            return -inf;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].query_pre(t[id].root, val);
        int ans = max(query_pre(id << 1, l, r, val), query_pre(id << 1 | 1, l, r, val));
        return ans;
    }
    int query_sub(int id, int l, int r, int val)
    {
        if (t[id].l > r || t[id].r < l)
            return inf;
        if (l <= t[id].l && t[id].r <= r)
            return t[id].query_sub(t[id].root, val);
        int ans = min(query_sub(id << 1, l, r, val), query_sub(id << 1 | 1, l, r, val));
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
    int op;
    T.build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        op = read();
        int l, r, val, pos;
        if (op == 3)
        {
            pos = read(), val = read();
            T.modify(1, pos, val);
            a[pos] = val;
            continue;
        }
        l = read(), r = read(), val = read();
        if (op == 1)
        {
            printf("%d\n", T.query_rank(1, l, r, val) + 1);
        }
        else if (op == 2)
        {
            printf("%d\n", T.query_val(l, r, val));
        }
        else if (op == 4)
        {
            printf("%d\n", T.query_pre(1, l, r, val));
        }
        else if (op == 5)
        {
            printf("%d\n", T.query_sub(1, l, r, val));
        }
    }
    return 0;
}
