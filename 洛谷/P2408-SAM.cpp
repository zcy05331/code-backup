#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

int n;
ll siz[MaxN];
char s[MaxN];

struct SuffixAutomaton
{
    struct state
    {
        int len, link;
        int next[26];
    };
    struct edge
    {
        int next, to;
    };
    edge e[MaxN << 1];
    state st[MaxN << 1];
    int cnt, size, last, vis[MaxN], head[MaxN];
    void sam_init() { size = 1, last = 1; }
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    void sam_build()
    {
        for (int i = 1; i <= size; i++)
            for (int j = 0; j < 26; j++)
                if (st[i].next[j])
                    add_edge(i, st[i].next[j]);
    }
    void dfs(int u)
    {
        if(vis[u]) return;
        siz[u] = (u > 1), vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
            dfs(e[i].to), siz[u] += siz[e[i].to];
    }
    void sam_extend(char c)
    {
        int cur = ++size, p = last;
        st[cur].len = st[p].len + 1;
        while (p && !st[p].next[c])
            st[p].next[c] = cur, p = st[p].link;
        if (p == 0)
            st[cur].link = 1;
        else
        {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else
            {
                int clone = ++size;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link, st[clone].len = st[p].len + 1;
                while (p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
} sam;

int main()
{
    sam.sam_init();
    scanf("%d\n%s", &n, s + 1);
    for (int i = 1; i <= n; i++)
        sam.sam_extend(s[i] - 'a');
    sam.sam_build(), sam.dfs(1);
    printf("%lld\n", siz[1]);
    return 0;
}
