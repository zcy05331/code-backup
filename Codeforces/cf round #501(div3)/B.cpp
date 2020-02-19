#include <iostream>
#include <cstdio>
using namespace std;

int ans[100005];

int main()
{
    int n, pos;
    string str1, str2;
    cin >> n >> str1 >> str2;
    for (register int i = 0; i < n; ++i)
    {
        register int j;
        for (j = i; j < n; ++j)
        {
            if (str1[j] == str2[i])
            {
                pos = j;
                break;
            }
        }
        if (j == n)
        {
            puts("-1");
            return 0;
        }
        while (pos > i)
        {
            swap(str1[pos], str1[pos - 1]);
            ans[++ans[0]] = pos;
            --pos;
            if (ans[0] > 10000)
            {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n", ans[0]);
    for (register int i = 1; i <= ans[0]; ++i)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}