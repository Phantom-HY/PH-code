#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int T, t[155], u[155], n, m;
vector<pair<int,int>>v;
void ddfs(int x, pair<int,int> step)
{
    if (x==n/2+1)
    {
        v.push_back(step);
    }
    if (step.x+t[x]<=m)ddfs(x+1,{step.x+t[x],step.y+u[x]});
    ddfs(x+1,step);
}
void dffs(int x, int step)
{
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", t + i, u + i);
    }
    return 0;
}