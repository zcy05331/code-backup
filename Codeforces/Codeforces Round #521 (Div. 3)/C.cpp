# include <bits/stdc++.h>

# define ll long long

struct p
{
    int id;
    ll x;
};

p a[200001];

int cmp(p x, p y){return x.x < y.x;}

std::vector<int> vec;

int main()
{
    int n;
    ll sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i].x), a[i].id = i, sum += a[i].x;
    std::sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        if(i != n)
        {
            if(sum - a[n].x - a[i].x == a[n].x)
                vec.push_back(a[i].id);
        }
        else 
        {
            if (sum - a[n - 1].x - a[i].x == a[n - 1].x)
                vec.push_back(a[i].id);
        }
    }
    if(vec.size())
    {
        printf("%d\n", vec.size());
        for(int i = 0; i < vec.size(); i++)
            printf("%d ", vec[i]);
    }
    else    
        printf("0");
    return 0;
}