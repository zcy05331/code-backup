#include <bits/stdc++.h>

#define R register
#define ll long long
#define ull unsigned ll
#define pir std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)

const int base = 233;
const int MaxN = 5e5 + 10;
const int mod = 1004535809;

struct mod_t
{
    int x;
    mod_t() {}
    mod_t(ll v) : x(v) {}
    mod_t(int v) : x(v) {}
    mod_t(long int v) : x(v) {}
    static int Mod(int x) { return ((x < 0) ? (x + mod) : x); }
    mod_t operator+(const mod_t y) const { return Mod(x + y.x - mod); }
    mod_t operator-(const mod_t y) const { return Mod(x - y.x); }
    mod_t operator*(const mod_t y) const { return (ll)x * y.x % mod; }
};

int n, now;
char s[MaxN];
std::vector<pir> vec;
mod_t pw1[MaxN], hs1[MaxN];
ull pw[MaxN], hs[MaxN];

int get1(int l, int r) { return (hs1[r] - hs1[l - 1] * pw1[r - l + 1]).x; }
ull get(int l, int r) { return hs[r] - hs[l - 1] * pw[r - l + 1]; }

struct SuffixAutomaton
{
    struct state
    {
        int len, link, nxt[27];
    } st[MaxN << 1];
    struct edge
    {
        int next, to;
    } e[MaxN << 1];
    int cnt, last, size, siz[MaxN], head[MaxN];
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
        for (int i = 2; i <= size; i++)
            add_edge(st[i].link, i);
    }
    void dfs(int u)
    {
        for (int i = head[u]; i; i = e[i].next)
            dfs(e[i].to), siz[u] += siz[e[i].to];
    }
    void extend(int c)
    {
        int cur = ++size, p = last;
        last = cur, st[cur].len = st[p].len + 1;
        while (p && !st[p].nxt[c])
            st[p].nxt[c] = cur, p = st[p].link;
        if (p == 0)
            st[cur].link = 1;
        else
        {
            int q = st[p].nxt[c];
            if (st[q].len == st[p].len + 1)
                st[cur].link = q;
            else
            {
                int clone = ++size;
                memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
                st[clone].link = st[q].link, st[clone].len = st[p].len + 1;
                while (p && st[p].nxt[c] == q)
                    st[p].nxt[c] = clone, p = st[p].link;
                st[q].link = st[cur].link = clone;
            }
        }
        siz[cur] = 1;
    }
} sam;

int main()
{
    scanf("%s", s + 1), n = strlen(s + 1);
    pw[0] = 1, pw1[0] = 1, sam.init();
    for (int i = 1; i <= n; i++)
    {
        sam.extend(s[i] - 'A' + 1);
        pw[i] = pw[i - 1] * base;
        pw1[i] = pw1[i - 1] * base;
        hs1[i] = hs1[i - 1] * base + s[i];
        hs[i] = hs[i - 1] * base + s[i];
    }
    now = 1, sam.build(), sam.dfs(1);
    for (int i = 1; i <= n; i++)
    {
        now = sam.st[now].nxt[s[i] - 'A' + 1];
        if (get(1, i) == get(n - i + 1, n))
            if (get1(1, i) == get1(n - i + 1, n))
                vec.push_back(mp(i, sam.siz[now]));
    }
    printf("%d\n", vec.size());
    for (int i = 0; i < vec.size(); i++)
        printf("%d %d\n", vec[i].first, vec[i].second);
    return 0;
}