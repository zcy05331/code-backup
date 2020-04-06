#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

char s[MaxN], p[MaxN];
int n, m, l, ans, a[MaxN], b[MaxN];

struct SuffixAutomaton
{
    struct edge
    {
        int next, to;
    };
    struct state
    {
        int len, link;
        int next[30];
    };
    edge e[MaxN];
    state st[MaxN];
    int cnt, size, last, min[MaxN], max[MaxN], head[MaxN];
    void init() { size = last = 1; }
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void build()
    {
        for(int i = 2; i <= size; i++)
            add_edge(st[i].link, i);
    }
    void dfs(int u)
    {
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            dfs(v), min[u] = std::min(min[u], min[v]);
            max[u] = std::max(max[u], max[v]);
        }
    }
    void extend(int c, int pos)
    {
        int cur = ++size, p = last;
        st[cur].len = st[p].len + 1;
        while (p && !st[p].next[c])
            st[p].next[c] = cur, p = st[p].link;
        if (!p)
            st[cur].link = 1;
        else
        {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else
            {
                int clone = ++size;
                min[clone] = max[clone] = max[q];
                memcpy(st[clone].next, st[q].next, sizeof st[q].next);
                st[clone].len = st[p].len + 1, st[clone].link = st[q].link;
                while (p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[cur].link = st[q].link = clone;
            }
        }
        last = cur, min[cur] = max[cur] = pos;
    }
} x, y;

void getpre()
{
    int now = 1;
    for(int i = 1; i <= l; i++)
    {
        int c = p[i] - 'A' + 1;
        if(!x.st[now].next[c])
            return;
        now = x.st[now].next[c], a[i] = x.min[now];
    }
}

void getsuf()
{
    int now = 1;
    for(int i = l; i; i--)
    {
        int c = p[i] - 'A' + 1;
        if(!y.st[now].next[c])
            return;
        now = y.st[now].next[c], b[i] = y.max[now];
    }
}

int main()
{
    x.init(), y.init();
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        x.extend(s[i] - 'A' + 1, i);
    for (int i = n; i; i--)
        y.extend(s[i] - 'A' + 1, i);
    x.build(), x.dfs(1), y.build(), y.dfs(1);
    scanf("%d", &m);
    while (m--)
    {
        int flag = 0;
        scanf("%s", p + 1), l = strlen(p + 1);
        memset(a, 0, 4 * (l + 5)), getpre();
        memset(b, 0, 4 * (l + 5)), getsuf();
        for (int i = 1; i < l; i++)
            if (a[i] && b[i + 1] && a[i] < b[i + 1])
                flag = 1;
        if(a[l]) flag = 1;
        if(l == 1) flag = 0;
        ans += flag;
    }
    printf("%d\n", ans);
    return 0;
}
