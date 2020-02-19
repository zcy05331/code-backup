#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

using std::pair;
using std::queue;
using std::set;
using std::vector;

const int MaxN = 2e5 + 10;

set<int> s;
queue<int> q;
int n, k, f[MaxN];
pair<int, int> a[MaxN];

inline int cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].first = read();
        a[i].second = i;
    }
    std::sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        q.push(a[i].second), s.insert(i);
    vector<int> v;
    int ans = 0;
    while (!s.empty())
    {
        v.clear();
        while (!s.count(q.front()))
            q.pop();
        int pos = q.front();
        q.pop();
        set<int>::iterator it = s.find(pos);
        for (int i = 1; i <= k + 1; i++)
        {
            v.push_back(*it);
            if (it == s.begin())
                break;
            --it;
        }
        it = next(s.find(pos));
        for (int i = 1; i <= k; i++)
        {
            if (it == s.end())
                break;
            v.push_back(*it);
            ++it;
        }
        for (int i = 0; i < v.size(); i++)
        {
            s.erase(v[i]);
            f[v[i]] = 1 + ans;
        }
        ans ^= 1;
    }
    for (int i = 1; i <= n; i++)
        printf("%d", f[i]);
    return 0;
}
