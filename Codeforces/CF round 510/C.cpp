#include <bits/stdc++.h>

const int MaxN = 200010;

int n;
std::pair<int, int> a[MaxN];
int cnt[3];
std::vector<int> vec, vec1;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first), a[i].second = i;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first < 0)
            cnt[0]++;
        else if (a[i].first == 0)
            cnt[1]++;
        else
            cnt[2]++;
    }
    if(cnt[0] == n && cnt[0] % 2)
    {
        int pmax = -0x7f7f7f7f, id = 0;
        for(int i = 1; i <= n; i++)
            if(a[i].first > pmax)
                id = i, pmax = a[i].first;
        printf("2 %d\n", a[id].second);
        for(int i = 1; i < id - 1; i++)
        {
            printf("1 %d %d\n", i, i + 1);
        }
        for(int i = id + 1; i < n; i++)
        {
            printf("1 %d %d\n", i, i + 1);
        }
        printf("1 %d %d\n", id - 1, n);
    }
    else if ((cnt[0] == 0 && cnt[1] == 0) || (cnt[0] == 1 && cnt[1] == n - 1) || (cnt[1] == n))
    {
        for (int i = 1; i < n; i++)
        {
            printf("1 %d %d\n", i, i + 1);
        }
        return 0;
    }
    else
    {
        std::sort(a + 1, a + n + 1);
        if (cnt[0] % 2)
        {
            int l = 0, r = 0;
            for (int i = 1; i <= n; i++)
                if (a[i].first < 0)
                    l = i;
            r = l;
            for (int i = 1; i <= n; i++)
                if (a[i].first == 0)
                    r = i;
            for (int i = l; i < r; i++)
                printf("1 %d %d\n", a[i].second, a[i + 1].second);
            printf("2 %d\n", a[r].second);
            for (int i = 1; i < l - 1; i++)
                printf("1 %d %d\n", a[i].second, a[i + 1].second);
            for (int i = r + 1; i < n; i++)
                printf("1 %d %d\n", a[i].second, a[i + 1].second);
            if (l > 1)
                printf("1 %d %d\n", a[l - 1].second, a[n].second);
        }
        else if(cnt[0] % 2 == 0)
        {
            for(int i = 1; i <= n; i++)
                if(a[i].first != 0)
                    vec.push_back(i);
            for(int i = 1; i <= n; i++)
                if(a[i].first == 0)
                    vec1.push_back(i);
            for(int i = 0; i < vec1.size() - 1; i++)
                printf("1 %d %d\n", a[vec1[i]].second, a[vec1[i + 1]].second);
            printf("2 %d\n", a[vec1[vec1.size() - 1]].second);
            for(int i = 0; i < vec.size(); i++)
                printf("1 %d %d\n", a[vec[i]].second, a[vec[i + 1]].second);
        }
    }
    return 0;
}