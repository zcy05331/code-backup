#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e6 + 10;
ll n, cnt, num;
char s[MaxN];
std::vector<int> vec;

int main()
{
    scanf("%I64d", &n);
    std::cin >> s + 1;
    cnt = n * (n - 1ll) / 2ll, num = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
        {
            int j = i;
            num = 1;
            while (j + 1 <= n && s[j + 1] == 'A')
                ++j, ++num;
            i = j;
            vec.push_back(num);
        }
        else
        {
            int j = i;
            num = 1;
            while (j + 1 <= n && s[j + 1] == 'B')
                ++j, ++num;
            i = j;
            vec.push_back(num);
        }
    }
    for (int i = 0; i < vec.size() - 1; i++)
        cnt -= vec[i] + vec[i + 1], ++cnt;
    printf("%I64d\n", cnt);
    return 0;
}
