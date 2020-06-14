#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int inf = 1e9 + 7;
const int MaxN = 1e5 + 10;

struct node
{
    int lc, rc, val;
    int rnd, cnt, size;
};

struct treap
{
    node t[MaxN];
    int size, root, ans;
    void pushup(int x) { t[x].size = t[t[x].lc].size + t[t[x].rc].size + t[x].cnt; }
    void rturn(int &x)
    {
        int y = t[x].lc;
        t[x].lc = t[y].rc, t[y].rc = x;
        t[y].size = t[x].size, pushup(x), x = y;
    }
    void lturn(int &x)
    {
        int y = t[x].rc;
        t[x].rc = t[y].lc, t[y].lc = x;
        t[y].size = t[x].size, pushup(x), x = y;
    }
    void insert(int &x, int val)
    {
        if (!x)
        {
            x = ++size;
            t[x].size = t[x].cnt = 1;
            t[x].val = val, t[x].rnd = rand();
            return;
        }
        t[x].size++;
        if (t[x].val == val)
            t[x].cnt++;
        else if (val > t[x].val)
        {
            insert(t[x].rc, val);
            if (t[t[x].rc].rnd < t[x].rnd)
                lturn(x);
        }
        else
        {
            insert(t[x].lc, val);
            if (t[t[x].lc].rnd < t[x].rnd)
                rturn(x);
        }
    }
    void del(int &x, int val)
    {
        if (!x) return;
        if (t[x].val == val)
        {
            if (t[x].cnt > 1)
                return (void)(t[x].cnt--, t[x].size--);
            if (!t[x].lc || !t[x].rc)
                x = t[x].lc + t[x].rc;
            else if (t[t[x].lc].rnd < t[t[x].rc].rnd)
                rturn(x), del(x, val);
            else
                lturn(x), del(x, val);
        }
        else if (val > t[x].val)
            t[x].size--, del(t[x].rc, val);
        else
            t[x].size--, del(t[x].lc, val);
    }
    int query_rank(int x, int val)
    {
        if (x == 0) return 0;
        if (t[x].val == val)
            return t[t[x].lc].size + 1;
        else if (val > t[x].val)
            return t[t[x].lc].size + t[x].cnt + query_rank(t[x].rc, val);
        else
            return query_rank(t[x].lc, val);
    }
    int query_num(int x, int val)
    {
        if (x == 0) return 0;
        if (val <= t[t[x].lc].size)
            return query_num(t[x].lc, val);
        else if (val > t[t[x].lc].size + t[x].cnt)
            return query_num(t[x].rc, val - t[t[x].lc].size - t[x].cnt);
        else
            return t[x].val;
    }
    void query_pre(int x, int val)
    {
        if (x == 0) return;
        if (t[x].val < val)
            ans = x, query_pre(t[x].rc, val);
        else
            query_pre(t[x].lc, val);
    }
    void query_sub(int x, int val)
    {
        if (x == 0) return;
        if (t[x].val > val)
            ans = x, query_sub(t[x].lc, val);
        else
            query_sub(t[x].rc, val);
    }
} T;

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
    int n = read(), op, x;
    while (n--)
    {
        op = read(), x = read();
        if (op == 1)
            T.insert(T.root, x);
        else if (op == 2)
            T.del(T.root, x);
        else if (op == 3)
            printf("%d\n", T.query_rank(T.root, x));
        else if (op == 4)
            printf("%d\n", T.query_num(T.root, x));
        else if (op == 5)
        {
            T.ans = 0, T.query_pre(T.root, x);
            printf("%d\n", T.t[T.ans].val);
        }
        else
        {
            T.ans = 0, T.query_sub(T.root, x);
            printf("%d\n", T.t[T.ans].val);
        }
    }
    return 0;
}
