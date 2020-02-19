#include <bits/stdc++.h>
const int MaxN = 500010;
struct progress
{
    int pid, arr_time, exe_time, prio, done;
    int operator<(progress b) const
    {
        return prio == b.prio ? b.arr_time < arr_time : prio < b.prio;
    }
};
progress p[MaxN];
std::priority_queue<progress> pq;
int main()
{
    int n = 1;
    int cur_time = 0, cur_id = 1;
    while (scanf("%d%d%d%d", &p[n].pid, &p[n].arr_time, &p[n].exe_time, &p[n].prio) != EOF)
        n++;
    int rest = n - 1;
    p[n].arr_time = 1e9;
    while(rest != 0)
    {
        if(pq.empty())
            pq.push(p[cur_id]), cur_time = p[cur_id].arr_time, cur_id++;
        progress tmp = pq.top();
        pq.pop();
        int last = cur_time;
        cur_time = std::min(p[cur_id].arr_time, last + tmp.exe_time);
        if(cur_time == last + tmp.exe_time)
            printf("%d %d\n", tmp.pid, cur_time), rest--;
        else
            tmp.exe_time -= cur_time - last, pq.push(tmp);
        if(cur_time == p[cur_id].arr_time)
            pq.push(p[cur_id]), cur_id++;
    }
    return 0;
}