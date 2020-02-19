#include <bits/stdc++.h>

std::string s1, s2;
int num[2][2];

int main()
{
    int n;
    scanf("%d", &n);
    std::cin >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        num[s1[i] - '0'][s2[i] - '0']++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '0' && s2[i] == '0')
            ans = ans + num[1][1] + num[1][0];
        if (s1[i] == '0' && s2[i] == '1')
            ans = ans + num[1][0];
        if (s1[i] == '1' && s2[i] == '0')
            ans = ans + num[0][0] + num[0][1];
        if (s1[i] == '1' && s2[i] == '1')
            ans = ans + num[0][0];
    }
    printf("%I64d", ans / 2);
    return 0;
}