#include <bits/stdc++.h>

struct s
{
    int id, score;
};

s t[1010];

int cmp(s a, s b)
{
    if(a.score != b.score)return a.score > b.score;
    return a.id < b.id;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        t[i].id = i;
        t[i].score = a + b + c + d;
    }
    std::sort(t + 1, t + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        if(t[i].id == 1)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}