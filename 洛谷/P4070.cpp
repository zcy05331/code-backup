#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

ll ans;
int n, a[MaxN];

struct SuffixAutomaton
{
    struct state
    {
        int len, link;
        std::unordered_map<int, int> next;
    };
    int size, last;
    state st[MaxN << 1];
    void sam_init() {size = last = 1;}
    void sam_extend(int c)
    {
        int cur = ++size, p = last;
        st[cur].len = st[p].len + 1;
        while(p && !st[p].next[c])
            st[p].next[c] = cur, p = st[p].link;
        if(p == 0)
            st[cur].link = 1;
        else
        {
            int q = st[p].next[c];
            if(st[q].len == st[cur].len + 1)
                st[cur].link = q;
            else 
            {
                int clone = ++size;
                st[clone].next = st[q].next;
                st[clone].len = st[p].len + 1, st[clone].link = st[q].link;
                while(p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[q].link = st[cur].link = clone;
            }
        } 
        last = cur, ans += st[cur].len - st[st[cur].link].len;
    }
}sam;

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{   
    n = read(), sam.sam_init();
    for(int i = 1; i <= n; i++)
        a[i] = read(), sam.sam_extend(a[i]), printf("%lld\n", ans);
    return 0;
}
