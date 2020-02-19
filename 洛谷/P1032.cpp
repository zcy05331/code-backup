#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)

int cnt, ans, ls;
std::string s, t;
std::string a[100], b[100];
std::map<std::string, int> map;

inline std::string change(std::string s, int x, int last)
{
    int len = s.length(), lena = a[x].length(), flag;
    std::string ret;
    for (int i = last; i < len - lena + 1; i++)
    {
        flag = 1;
        for (int j = 0; j < lena; j++)
        {
            if (s[i + j] != a[x][j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ls = i + lena - 1;
            for (int j = 0; j < i; j++)
                ret += s[j];
            ret += b[x];
            for (int j = i + lena; j < len; j++)
                ret += s[j];
            return ret;
        }
    }
    ls = -1;
    ret = "";
    return ret;
}

inline void dfs(int m, int dep, std::string s)
{
    if (s == t)
        ans = 1;
    if (ans)
        return;
    if (m == dep || map[s] == 1)
        return;
    map[s] = 1;
    //std::cout << s << "\n";
    for (int i = 1; i <= cnt; i++)
    {
        int len = s.length();
        std::string tmp;
        for (int j = 0; j < len; j++)
        {
            tmp = change(s, i, j);
            if (tmp.length() == 0)
                break;
            dfs(m, dep + 1, tmp);
            if (ans)
                return;
        }
    }
}

int main()
{
    std::cin >> s >> t;
    cnt = 0;
    while (!std::cin.eof())
    {
        ++cnt;
        std::cin >> a[cnt] >> b[cnt];
    }
    for (int i = 1; i <= 10; i++)
    {
        map.clear();
        dfs(i, 0, s);
        if (ans)
            return 0 * printf("%d\n", i);
    }
    printf("NO ANSWER!");
    return 0;
}
