#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
int n, a[200];
std::vector<int> vec;
int main()
{   
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a +1, a + n + 1);
    for(int i = 1; i <= n; i++)
        if(a[i] != a[i - 1])
            vec.push_back(a[i]);
    if(vec.size() > 3)
        return 0 * printf("-1");
    if(vec.size() == 1)
        return 0 * printf("0");
    else if(vec.size() == 2)
    {
        if((vec[1] - vec[0]) % 2 == 0)
            return 0 * printf("%d", abs(vec[0] - vec[1]) / 2);
        else return 0 * printf("%d", abs(vec[0] - vec[1]));
    }
    else if(vec.size() == 3)
    {
        if(abs(vec[0] - vec[1]) != abs(vec[1] - vec[2]))
            return 0 * printf("-1");
        else printf("%d", abs(vec[0] - vec[1]));
    }
    return 0;
}
