#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int a[100][100];  
int main()  
{  
    int i,j,n,k;  
    cin >> n;  
    memset(a,0,sizeof(a));  
    a[0][(n)/2]=1; i=1; j=(n)/2;  
    for (k=2; k <= n*n; k++)  
    {  
        if ((i==0)&&(j!=n-1))  
        {  
            a[n][j+1]=k;  
            i=n; j++;  
            continue; 
        }  
        if ((j==n-1)&&(i!=0))  
        {  
            a[i-1][1]=k;  
            i--; j=1;  
            continue;  
        }  
        if ((i==0)&&(j==n-1))  
        {  
            a[i+1][j]=k;  
            i++;  
            continue;  
        }  
        if ((i!=0)&&(j!=n-1))  
        {  
            if (a[i-1][j+1]==0)  
            {  
                a[i-1][j+1]=k;  
                i--; j++;  
            }  
            else  
            {  
                a[i+1][j]=k;  
                i++;  
            }  
        }  
    }  
    for (i=0; i < n; i++)  
    {  
        for (j=0; j < n; j++)  
            cout << a[i][j] << ' ';  
        cout << endl;  
    }  
    return 0;  
}   
