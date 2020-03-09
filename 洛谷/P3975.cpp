#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

int n, t, k;
char s[MaxN];

struct SuffixAutomaton
{
    struct state
    {
        int len, link;
        int next[30];
    };
    struct edge
    {
        int next, to;
    };
    edge e[MaxN];
    state st[MaxN];
    int cnt, size, last, siz[MaxN], sum[MaxN], head[MaxN];
    void sam_init() { size = last = 1; }
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
    void dfs1(int u)
    {
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            dfs1(v), sum[u] += sum[v];
        }
    }
    void dfs(int u)
    {
        if (siz[u]) return;
        siz[u] = (t ? sum[u] : 1);
        for (int i = 1; i <= 26; i++)
        {
            int v = st[u].next[i];
            if (v)
                dfs(v), siz[u] += siz[v];
        }
    }
    void get(int u, int k)
    {
        if (k <= 0) return;
        for (int i = 1; i <= 26; i++)
        {
            int v = st[u].next[i];
            if (v)
            {
                if (siz[v] < k)
                    k -= siz[v];
                else
                {
                    k -= (t ? sum[v] : 1);
                    putchar(i + 'a' - 1), get(v, k);
                    break;
                }
            }
        }
    }
    void sam_extend(int c)
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
                st[clone].len = st[p].len + 1, st[clone].link = st[q].link;
                while (p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur, sum[cur] = 1;
    }
} sam;

int main()
{
    sam.sam_init();
    scanf("%s%d%d", s + 1, &t, &k), n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        sam.sam_extend(s[i] - 'a' + 1);
    sam.sam_build(), sam.dfs1(1);
    sam.dfs(1), sam.siz[1]--;
    if (sam.siz[1] < k)
        return 0 * puts("-1");
    else
        sam.get(1, k);
    // puts("");
    // for (int i = 1; i <= sam.size; i++)
    //     printf("%d ", sam.sum[i]);
    return 0;
}
