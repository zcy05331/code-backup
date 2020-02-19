#include <bits/stdc++.h>

std::vector<int> v;
int n,m,k;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < 4; j++)
        {
            int t;
            scanf("%d", &t);
            sum += t;
        }
        v.push_back(sum);
    }
    int s = v[0];
    std::sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
    {
        if(s == v[i])
        {
            printf("%d",i + 1);
            return 0;
        }
    }
    return 0;
}