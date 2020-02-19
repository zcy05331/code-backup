#include <bits/stdc++.h>

std::vector<std::string> v;
std::string tmp;
int n;

void work1()
{

}

void work2()
{

}

int main()
{
    int cnt;
    while(std::cin >> tmp)v.push_back(tmp), cnt++;
    if(v[0] == "0" || v[0] == "1")n = (cnt - 1) >> 1,work1();
    else n = (cnt >> 1) - 1,work2();
    return 0;
}
