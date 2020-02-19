#include <bits/stdc++.h>
const char word[30][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"}; //对应
const int num[30] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 00, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};
int a[10], top, flag;
char s[100];
int main()
{
    for (int i = 1; i <= 6; i++)
    {
        std::cin >> s;
        for (int j = 1; j <= 26; j++)
        {
            if (!strcmp(s, word[j]))
            {
                a[++top] = num[j];
                break;
            }
        }
    }
    std::sort(a + 1, a + top + 1);
    for (int i = 1; i <= top; i++)
    {
        if (flag)
            printf("%d", a[i]);
        else
        {
            if (a[i])
            {
                printf("%d", a[i]);
                flag = 1;
            }
        }
    }
    if (!flag)
        printf("0");
    return 0;
}