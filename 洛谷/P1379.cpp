#include<bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
queue<long long >q;
long long start, over;
map<long long, int >ans;
inline long long pow10 ( int s )
{
    register long long x=1;
    for ( register int i = 0; i < s; i++ )
        x *= 10;
    return x;
}
inline int getith ( long long x, int s )
{
    return ( x / pow10 ( s ) ) % 10;
}
inline int bfs ( long long x )
{
    q.push ( x );
    ans[x] = 0;
    while ( !q.empty() )
    {
        register long long tmp = q.front();
        q.pop();
        if ( tmp == over )
            break;
        else
        {
            for ( register int i = 0; i < 4; i++ )
            {
                register int pos;
                for ( register int j = 0; j < 9; j++ )
                    if ( getith ( tmp, j ) == 0 )
                    {
                        pos = j;
                        break;
                    }
				//prregister intf("pos=%d\n",pos);
                register int posx = pos / 3 , posy = pos % 3;
                register int nposx = posx + dx[i], nposy = posy + dy[i];
                if(nposx<0||nposx>2||nposy<0||nposy>2)continue;
                register int newp = nposx * 3 + nposy;
                register int ith=getith(tmp,newp);
                register long long s;
                //prregister intf("i=%d\n",ith);
                s=tmp;
                s-=pow10(newp)*ith;
                s+=pow10(pos)*ith;
                if ( ans[s]!=0&&ans[s]<ans[tmp]+1 )
                    continue;
                else
                {
                    ans[s] = ans[tmp] + 1;
                    q.push ( s );
                }

            }
        }
    }
}
int main()
{
    register long long x;
    scanf ( "%lld", &x );
    start = x;
    over = 123804765ll;
    bfs ( start );
    printf ( "%d", ans[over] );
    return 0;
}
