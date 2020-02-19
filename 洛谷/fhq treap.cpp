# include <bits/stdc++.h>

const int MaxN = 100010;

inline int read()
{
    bool f = 0;
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = true;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    return (!f) ? x : -x;
}

struct node
{
    int size, val, rand, l, r;
};

struct fhq_treap
{
    node t[MaxN];
    int cnt, root;
    inline int add_node(int val)
    {
        ++cnt;
        t[cnt].size = 1;
        t[cnt].rand = rand();
        t[cnt].val = val;
        t[cnt].l = t[cnt].r = 0;
        return cnt;
    }
    inline void init()
    {
        add_node(2147483647);
        t[1].size = 0;
    }
    inline void update(int k)
    {
        t[k].size = t[t[k].l].size + t[t[k].r].size + 1;
    }
    inline void split(int now, int &a, int &b, int val)
    {
        if(now == 0)
            return (void) (a = b = 0);
        if(t[now].val <= val)
            a = now, split(t[now].r, t[a].r, b, val);
        else b = now, split(t[now].l, a, t[b].l, val);
        update(now);
    }
    inline void merge(int &now, int a, int b)
    {
        if((!a) || (!b))
            return (void) (now = a + b);
        if(t[a].rand < t[b].rand)
            now = a, merge(t[now].r, t[a].r, b);
        else    
            now = b, merge(t[now].l, a, t[b].l);
        update(now);
    }
    inline void insert(int val)
    {
        register int x = 0, y = 0, z;
        z = add_node(val);
        split(root, x, y, val);
        merge(x, x, z);
        merge(root, x, y);
    }
    inline void del(int val)
    {
        register int x = 0, y = 0, z = 0;
        split(root, x, y, val);
        split(x, x, z, val - 1);
        merge(z, t[z].l, t[z].r);
        merge(x, x, z);
        merge(root, x, y);
    }
    inline int find(int now, int rank)
    {
        while(t[t[now].l].size + 1 != rank)
        {
            if(t[t[now].l].size >= rank)
                now = t[now].l;
            else 
                rank -= ((t[t[now].l]).size + 1) , now = t[now].r;
        }
        return t[now].val;
    }
    inline int query_rank(int val)
    {
        register int x = 0, y = 0;
        split(root, x, y, val - 1);
        register int ans = t[x].size + 1;
        merge(root, x, y);
        return ans;
    }
    inline int query_num(int rank)
    {
        return find(root, rank);
    }
    inline int query_pre(int val)
    {
        register int x = 0, y = 0;
        split(root, x, y, val - 1);
        register int ans = find(x, t[x].size);
        merge(root, x, y);
        return ans;
    }
    inline int query_sub(int val)
    {
        register int x = 0, y = 0;
        split(root, x, y, val);
        register int ans = find(y, 1);
        merge(root, x, y);
        return ans;
    }
}t;

int main()
{
    int n;
    n = read();
    srand(time(NULL));
    for(unsigned i = 1; i <= n; ++i)
    {
        int op, x;
        op = read(), x = read();
        # define out(x) printf("%d\n", x)
        if(op == 1) t.insert(x);
        if(op == 2) t.del(x);
        if(op == 3) out(t.query_rank(x));
        if(op == 4) out(t.query_num(x));
        if(op == 5) out(t.query_pre(x));
        if(op == 6) out(t.query_sub(x));
    }
    return 0;
}