#include <bits/stdc++.h>

#define R register
#define ll long long
#define P std::pair<std::string, int>
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) (((a) + (b)) % mod)

int n, ans = 15;
std::string st, ed;
std::map<std::string, int> m1, m2;
std::queue<std::pair<std::string, int>> q1, q2;

inline void init()
{
    ans = 15, m1.clear(), m2.clear();
    while (!q1.empty())
        q1.pop();
    while (!q2.empty())
        q2.pop();
}

inline void bfs1(int lim)
{
    while (!q1.empty())
    {
        P tmp = q1.front();
        if (tmp.second > lim)
            break;
        q1.pop();
        std::string s = tmp.first;
        for (int i = 0; i < n; i++)
        {
            std::string t = s;
            t[i] = (((t[i] - '0') + 1) % 10) + '0';
            if (m1[t] || t == st)
                continue;
            m1[t] = tmp.second + 1, q1.push(mp(t, m1[t]));
        }
        for (int i = 1; i < n; i++)
        {
            std::string t = s;
            std::swap(t[i], t[i - 1]);
            if (m1[t] || t == st)
                continue;
            m1[t] = tmp.second + 1, q1.push(mp(t, m1[t]));
        }
    }
}

inline void bfs2(int lim)
{
    while (!q2.empty())
    {
        P tmp = q2.front();
        if (tmp.second > lim)
            break;
        q2.pop();
        std::string s = tmp.first;
        for (int i = 0; i < n; i++)
        {
            std::string t = s;
            t[i] = (((t[i] - '0') + 9) % 10) + '0';
            if (m2[t] || t == ed)
                continue;
            m2[t] = tmp.second + 1, q2.push(mp(t, m2[t]));
        }
        for (int i = 1; i < n; i++)
        {
            std::string t = s;
            std::swap(t[i], t[i - 1]);
            if (m2[t] || t == ed)
                continue;
            m2[t] = tmp.second + 1, q2.push(mp(t, m2[t]));
        }
    }
}

int main()
{
    int T = 3;
    while (T--)
    {
        init();
        scanf("%d", &n);
        std::cin >> st >> ed;
        if (st == ed)
        {
            printf("%d\n", 0);
            continue;
        }
        q1.push(mp(st, 0)), q2.push(mp(ed, 0));
        bfs1(5), bfs2(5);
        m1[st] = 0, m2[ed] = 0;
        for (std::map<std::string, int>::iterator it = m1.begin(); it != m1.end(); it++)
            if (m2[it->first] != 0 || it->first == ed)
                ans = std::min(ans, it->second + m2[it->first]);
        printf("%d\n", ans);
    }
    return 0;
}
