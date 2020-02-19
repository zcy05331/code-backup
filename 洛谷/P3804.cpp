#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e6 + 10;

ll ans = 0;

struct SuffixAutomaton
{
    struct state
    {
        int len, link, next[30];
    };
    struct edge
    {
        int next, to;
    };
    edge e[MaxN << 2];
    state st[MaxN << 1];
    int cnt, size, last, head[MaxN], siz[MaxN];
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
        for (int i = 2; i <= size; i++)
            add_edge(st[i].link, i);
    }
    void dfs(int u)
    {
        for (int i = head[u]; i; i = e[i].next)
            dfs(e[i].to), siz[u] += siz[e[i].to];
        if (siz[u] > 1)
            ans = std::max(ans, st[u].len * 1ll * siz[u]);
    }
    void sam_extend(char c)
    {
        int cur = ++size, p = last;
        last = cur, st[cur].len = st[p].len + 1;
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
        siz[cur] = 1;
    }
} sam;

int main()
{
    std::string s;
    std::cin >> s;
    int len = s.length();
    sam.sam_init();
    for (int i = 0; i < len; i++)
        sam.sam_extend(s[i] - 'a');
    sam.sam_build(), sam.dfs(1);
    printf("%lld\n", ans);
    return 0;
}
