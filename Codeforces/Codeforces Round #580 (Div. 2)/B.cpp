#include <bits/stdc++.h>
using namespace std;
long long tmp, n, tot;
int zero, posi, nega;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        if (!tmp)
            zero++;
        else
        {
            if (tmp >= 1)
                posi++, tot += (tmp - 1);
            else
            {
                if (tmp <= -1)
                    nega++, tot += (-tmp - 1);
            }
        }
    }
    if (!zero)
    {
        if (nega % 2 == 0)
            cout << tot;
        else
            cout << tot + 2LL;
    }
    else
    {
        if (nega % 2 == 0)
            cout << tot + (long long)zero;
        else
            cout << tot + (long long)zero;
    }