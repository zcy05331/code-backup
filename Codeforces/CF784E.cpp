#include<bits/stdc++.h>
using namespace std;
int main()
{
    int in1,in2,in3,in4;
    scanf("%d%d%d%d",&in1,&in2,&in3,&in4);
    printf("%d",((in1^in2) & (in3 | in4)) ^ ((in2&in3) | (in1^in4)));
    return 0;
}
