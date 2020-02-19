#include<bits/stdc++.h>
using namespace std;
int len[200001],s[200001],tmp[20001];
vector<int>a[200001];
int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
	{
        scanf("%d",&len[i]);
        for(int j=0;j<len[i];j++)
		{
            int tmp;
            scanf("%d",&tmp);
            s[i]+=tmp;
		}
		for(int j=0;j<len[i];j++)
		{
            a[i].push_back();
		}
	}
    return 0;
}
