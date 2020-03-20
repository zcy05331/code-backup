#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;

int n, m;
char s[MaxN], t[MaxN];

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
    int cnt, size, last, head[MaxN], siz[MaxN][11];
    bool check(int u)
    {
        if (!u) return 0;
        for (int i = 1; i <= m; i++)
            if (!siz[u][i])
                return 0;
        return 1;
    }
    void init()
    {
        memset(head, 0, sizeof(head));
        memset(siz, 0, size * sizeof(int[11]));
        memset(st, 0, size * sizeof(state));
        cnt = size = last = 0;
    }
    void add_edge(int u, int v)
    {
        ++cnt;
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt;
    }
    int lcs()
    {
        n = strlen(s + 1);
        int c, now = 1, len = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            c = s[i] - 'a';
            while (now && !check(st[now].next[c]))
                now = st[now].link, len = st[now].len;
            if (!now) now = 1, len = 0;
            if (check(st[now].next[c]))
                now = st[now].next[c], len++;
            ans = std::max(ans, len);
        }
        return ans;
    }
    void dfs(int u)
    {
        int v;
        for (int i = head[u]; i; i = e[i].next)
        {
            v = e[i].to, dfs(v);
            for (int j = 1; j <= m; j++)
                siz[u][j] |= siz[v][j];
        }
    }
    void sam_build()
    {
        size = 1, scanf("%d", &m);
        for(int k = 1; k <= m; k++)
        {
            scanf("%s", s + 1);
            n = strlen(s + 1), last = 1;
            for (int i = 1; i <= n; i++)
                sam_extend(s[i] - 'a', k);
        }
        for (int i = 2; i <= size; i++)
            add_edge(st[i].link, i);
    }
    void sam_extend(int c, int id)
    {
        int cur = ++size, p = last;
        st[cur].len = st[p].len + 1, siz[cur][id] = 1;
        while (p && !st[p].next[c])
            st[p].next[c] = cur, p = st[p].link;
        if (!p)
            st[cur].link = 1;
        else
        {
            int q = st[p].next[c];
            if (st[q].len == st[p].len + 1)
                st[cur].link = q;
            else
            {
                int clone = ++size;
                memcpy(st[clone].next, st[q].next, sizeof st[q].next);
                st[clone].len = st[p].len + 1, st[clone].link = st[q].link;
                while (p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[cur].link = st[q].link = clone;
            }
        }
        last = cur;
    }
} sam;

int main()
{
    int T = 1;
    while (T--)
    {
        sam.init(), sam.sam_build(), sam.dfs(1);
        printf("%d\n", sam.lcs());
    }
    return 0;
}