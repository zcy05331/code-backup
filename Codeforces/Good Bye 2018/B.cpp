# include <bits/stdc++.h>
# define p std::pair<int, int> 

p pos[1010], change[1010];

std::map<p, int> m, tmp;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &pos[i].first, &pos[i].second);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &change[i].first, &change[i].second), m[change[i]]++;
    for(int i = 1; i <= n; i++)
    {
        p T;
        T.first = pos[i].first + change[1].first;
        T.second = pos[i].second + change[1].second;
        tmp = m;
        int flag = true;
        for(int j = 1; j <= n; j++)
        {
            p tem;
            tem.first = T.first - pos[j].first;
            tem.second = T.second - pos[j].second;
            if(!tmp[tem])
                flag = false;
            --tmp[tem];
        }
        if(flag)
            return 0 * printf("%d %d\n", T.first, T.second);
    }
    return 0;
}