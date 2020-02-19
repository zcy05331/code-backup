#include <bits/stdc++.h>
using namespace std;
char k[101], c[1001];
int to[101], upper[1001];
int main()
{
    scanf("%s", k);
    scanf("%s", c);
    int lenc = strlen(c), lenk = strlen(k);
    for (int i = 0; i < lenk; i++)
    {
        to[i] = tolower(k[i]) - 'a';
    }
    for (int i = 0; i < lenc; i++)
    {
        if (isupper(c[i]))
            upper[i] = 1;
    }
    int x = 0;
    for (int i = 0; i < lenc; i++)
    {
        int s = int(c[i]) - to[x];
        if (upper[i] && !(isupper(s)))
            s += 26;
        else if (!upper[i] && !(islower(s)))
            s += 26;
        putchar(s);
        x++;
        if (x == lenk)
            x = 0;
    }
    return 0;
}
