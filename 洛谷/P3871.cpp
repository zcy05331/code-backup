#include <bits/stdc++.h>

#define R register
#define ll long long
#define lc t[x].ch[0]
#define rc t[x].ch[1]
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

struct node
{
    int ch[2], val;
    int rnd, cnt, size;
};

int n, m, a[MaxN];

struct treap
{
    node t[MaxN];
    int root, cnt;
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
            return (void)t[x].cnt++;
        int c = t[x].val > val;
        insert(t[x].ch[c], val);
        if (t[x].rnd > t[t[x].ch[c]].val)
            rotate(x, c);
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
} T;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? x : (-x);
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), T.insert(T.root, -a[i]);
    m = read();
    char op[10];
    for(int i = 1, x; i <= m; i++)
    {
        scanf("%s", op + 1);
        if(op[1] == 'a')
            x = read(), T.insert(T.root, -x);
        else printf("%d\n", -T.query_val(T.root, (T.t[T.root].size + 1) / 2));
    }
    return 0;
}
