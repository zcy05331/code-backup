#include <bits/stdc++.h>

#define R register
#define ll long long
#define calc(a, b) (b - a - 1)
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e5 + 10;

int n;
int a[MaxN];
std::vector<int> vec[4], v, tmp;
std::map<int, int> m, vis;

int check(int mid)
{
    v = vec[1];
    vis.clear(), tmp.clear();
    if (vec[3].size())
    {
        for (int i = 0; i < vec[3].size(); i++)
            tmp.push_back(vec[3][i]);
        for (int i = 0; i < vec[2].size(); i++)
            tmp.push_back(vec[2][i]);
        // for (int i = 0; i < tmp.size(); i++)
        //     printf("%d ", tmp[i]);
        // puts("");
        while (tmp.size() <= mid)
        {
            if (!v.size())
                return 0;
            tmp.push_back(v.back()), v.pop_back();
        }
        tmp.clear();
        for (int i = 0; i < vec[3].size(); i++)
            tmp.push_back(vec[3][i]);
        for (int i = 0; i < vec[2].size(); i++)
            tmp.push_back(vec[2][i]);
        while (tmp.size() <= mid)
        {
            if (!v.size())
                return 0;
            tmp.push_back(v.back()), v.pop_back();
        }
        return 1;
    }
    else
    {
        if (vec[2].size() + vec[1].size() > mid)
            return true;
        return false;
    }
}

int main()
{
    int tmp = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), m[a[i]]++, tmp += ((m[a[i]] == 1) ? 1 : 0);
    if (tmp == n)
        return 0 * printf("%d\n", n);
    for (int i = 1; i <= n; i++)
        if (!vis[a[i]])
            vis[a[i]] = 1, vec[m[a[i]]].push_back(a[i]);
    for (int i = 1; i <= 3; i++)
        std::sort(vec[i].begin(), vec[i].end());
    int l = 0, r = n + 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}
