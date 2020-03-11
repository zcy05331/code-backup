#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e5 + 10;

int n, m;
char s[MaxN], t[MaxN];

struct SuffixAutomaton
{
    struct state
    {
        int len, link;
        int next[30];
    };
    int size, last;
    state st[MaxN << 1];
    void sam_init() { size = last = 1;} 
    int lcs()
    {
        int c, now = 1, len = 0, ans = 0;
        for(int i = 1; i <= m; i++)
        {
            c = t[i] - 'a';
            while(now && !st[now].next[c])
                now = st[now].link, len = st[now].len;
            if(!now) now = 1, len = 0;
            if(st[now].next[c])
                now = st[now].next[c], len++;
            ans = std::max(ans, len);
        }
        return ans;
    }
    void sam_extend(int c)
    {
        int cur = ++size, p = last;
        st[cur].len = st[p].len + 1;
        while(p && !st[p].next[c])
            st[p].next[c] = cur, p = st[p].link;
        if(!p)
            st[cur].link = 1;
        else
        {
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else
            {
                int clone = ++size;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link, st[clone].len = st[p].len + 1;
                while(p && st[p].next[c] == q)
                    st[p].next[c] = clone, p = st[p].link;
                st[cur].link = st[q].link = clone;
            }
        }
        last = cur;
    }
}sam;

int main()
{   
    sam.sam_init(), scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for(int i = 1; i <= n; i++)
        sam.sam_extend(s[i] - 'a');
    printf("%d", sam.lcs());
    return 0;
}
