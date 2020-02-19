#include <bits/stdc++.h>
#define R register
#define ll long long
#define cmin(a, b) ((a < b) ? a : b)
#define cmax(a, b) ((a < b) ? b : a)
const int MaxN = 100010;
int n, t, q;
std::vector<int> a[MaxN], x;
int s[MaxN], cnt[MaxN], r[MaxN];
std::map<int, int> m;
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
    ll ans = 0;
    n = read(), t = read(), q = read();
    for(int i = 1; i <= t; i++)
        s[i] = read(), cnt[s[i]]++;
    for(int i = 1; i <= n; i++)
    {
        int len, tmp;
        len = read();
        for(int j = 1; j <= len; j++)
            tmp = read(), a[i].push_back(tmp);
    }
    int rcnt = read();
    for(int i = 1; i <= rcnt; i++)
        r[i] = read();
    for(int i = 1; i <= q; i++)
    {   
        m.clear();
        for(int j = 0; j < a[r[(i - 1) % rcnt + 1]].size(); j++)
            x.push_back(a[r[(i - 1) % rcnt + 1]][j]);
        if(x.size() < t)
            continue;
        int size = x.size() - 1;
        for(int j = 0; j < t; j++)
            m[x[size - j]]++;
        int tmp = 1;
        for(int i = 1; i <= t; i++)
            if(cnt[s[i]] != m[s[i]])
                tmp = 0;
        ans += tmp;
    }   
    printf("%lld\n", ans);
    return 0;
}
