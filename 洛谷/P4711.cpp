// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
map<string, double> element;
void init()
{
    element["H"] = 1.000000;
    element["C"] = 12.000000;
    element["N"] = 14.000000;
    element["O"] = 16.000000;
    element["F"] = 19.000000;
    element["Na"] = 23.000000;
    element["Mg"] = 24.000000;
    element["Al"] = 27.000000;
    element["Si"] = 28.000000;
    element["P"] = 31.000000;
    element["S"] = 32.000000;
    element["Cl"] = 35.500000;
    element["K"] = 39.000000;
    element["Ca"] = 40.000000;
    element["Mn"] = 55.000000;
    element["Fe"] = 56.000000;
    element["Cu"] = 64.000000;
    element["Zn"] = 65.000000;
    element["Ag"] = 108.000000;
    element["I"] = 127.000000;
    element["Ba"] = 137.000000;
    element["Hf"] = 178.500000;
    element["Pt"] = 195.000000;
    element["Au"] = 197.000000;
    element["Hg"] = 201.000000;
}
string s;
int isnum(char x)
{
    if (x <= '9' && x >= '0')
        return 1;
    return 0;
}
int en;
int len;
double getx(int st)
{

    for (int i = st; i < len; i++)
    {
        if (s[i] == ')')
        {
            en = i;
            break;
        }
    }
    double ret = 0;
    for (int i = st + 1; i < en; i++)
    {
        if (isupper(s[i]))
        {
            string tmp = " ";
            tmp[0] = s[i];
            int b = 0;
            //cout<<tmp<<endl;
            if (islower(s[i + 1]))
            {
                tmp += s[i + 1];
                if (s[i + 2] == '_')
                {
                    int a = i + 4;

                    while (isnum(s[a]))
                    {
                        b = b * 10 + s[a] - '0';
                        a++;
                    }
                }
            }

            double tmp2 = element[tmp];
            //cout<<tmp<<" "<<tmp2<<endl;

            if (s[i + 1] == '_')
            {
                int a = i + 3;

                while (isnum(s[a]))
                {
                    b = b * 10 + s[a] - '0';
                    a++;
                }
            }

            if (b == 0)
                b = 1;
            ret += b * 1.0 * tmp2;
            //cout<<tmp<<ends<<tmp2<<ends<<b<<ends<<ret<<endl;
        }
        else
            continue;
    }
    return ret;
}
int main()
{
    init();
    double ans = 0;
    cin >> s;
    int H2O = 0;
    len = s.length();

    for (int i = 0; i < len; i++)
    {

        if (isupper(s[i]))
        {
            string tmp = " ";
            tmp[0] = s[i];
            int b = 0;
            //cout<<tmp<<endl;
            if (islower(s[i + 1]))
            {
                tmp += s[i + 1];
                if (s[i + 2] == '_')
                {
                    int a = i + 4;

                    while (isnum(s[a]))
                    {
                        b = b * 10 + s[a] - '0';
                        a++;
                    }
                }
            }

            double tmp2 = element[tmp];
            //cout<<tmp<<" "<<tmp2<<endl;

            if (s[i + 1] == '_')
            {
                int a = i + 3;

                while (isnum(s[a]))
                {
                    b = b * 10 + s[a] - '0';
                    a++;
                }
            }

            if (b == 0)
                b = 1;
            ans += b * 1.0 * tmp2;
            //cout<<tmp<<ends<<tmp2<<ends<<b<<ends<<ans<<endl;
        }
        if (s[i] == '(')
        {
            int tmp = getx(i);
            int b = 0;
            if (s[en + 1] == '_')
            {
                int a = en + 3;

                while (isnum(s[a]))
                {
                    b = b * 10 + s[a] - '0';
                    a++;
                }
            }
            if (b == 0)
                b = 1;
            ans += b * 1.0 * tmp;
            //cout<<ans<<endl;
            i = en;
        }
        if (s[i] == '~')
        {
            H2O = i;
            break;
        }
        else
            continue;
    }

    if (H2O != 0)
    {
        if (!isnum(s[H2O + 1]))
        {
            ans += 18.0;
            //puts( "YES" );
        }
        else
        {
            int w = 0;
            while (isnum(s[H2O + 1]))
            {
                w = w * 10.0 + (s[H2O + 1] - '0');
                H2O++;
            }
            ans += w * 18.0;
        }
    }
    cout << ans;
    return 0;
}