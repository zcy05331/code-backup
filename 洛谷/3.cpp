#include <bits/stdc++.h>
using namespace std;
char a[100] = {};
int main()
{
    cin.getline(a, 100);
    if (a[0] == '-')
        cout << '-';
    int len = strlen(a);
    bool is = 0;
    if (a[0] == '0')
    {
        cout << "0";
        return 0;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        if (((is && a[i] == '0') || a[i] != '0') && a[i] != '-')
        {
            is = 1;
            cout << a[i];
        }
    }
    return 0;
}
