#include <bits/stdc++.h>
const int mod = 998244353;
int a[100];
std::vector<int> v;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        a[i] = i;
    do
    {
        for(int i = 1; i <= n; i++)
            v.push_back(a[i]);
    }
    while(std::next_permutation(a + 1, a + n + 1));
    int ans = 1, sum = n * (n + 1) / 2;
    for(int i = n; i < v.size(); i++)
    {
        sum += v[i];
        sum -= v[i - n];
        if(sum == n * (n + 1) / 2)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}