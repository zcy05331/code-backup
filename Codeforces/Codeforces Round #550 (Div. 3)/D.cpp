#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define openfile(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
const int MaxN = 2e5 + 10;
int n;
int a[MaxN], cnt[MaxN];
std::vector<int> vec;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), ++cnt[a[i]];
    int max = 0, num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (max < cnt[a[i]])
            max = cnt[a[i]], num = a[i];
    }
    printf("%d\n", n - max);
    if (max == n)
        return 0;
    vec.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == num)
            vec.push_back(i);
    }
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = vec[i] - 1; j > vec[i - 1]; j--)
        {
            if (a[j] > num)
                printf("%d %d %d\n", 2, j, j + 1);
            else
                printf("%d %d %d\n", 1, j, j + 1);
        }
    }
    if (vec[vec.size() - 1] < n)
    {
        for (int i = vec[vec.size() - 1] + 1; i <= n; i++)
        {
            if (a[i] > num)
                printf("%d %d %d\n", 2, i, i - 1);
            else
                printf("%d %d %d\n", 1, i, i - 1);
        }
    }
    return 0;
}
