#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int n,m,sx,sy,ex,ey;
int fx[8][2] = {{-1,2},{1,2},{-1,-2},{1,-2},{-2,1},{2,1},{-2,-1},{2,-1}};
bool f[405][405];
int bfs(int x,int y)
{
    queue<pair<pair<int,int>,int>>q;
    q.push({{x,y},0});
    f[x][y]=1;
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        if(t.x.x==ex&&t.x.y==ey)
            return t.y;
        for (int i = 0; i < 8; i++)
        {
            int tx = t.x.x + fx[i][0], ty = t.x.y + fx[i][1];
            if (tx < 1 || ty < 1 || tx > n || ty > m || f[tx][ty])
                continue;
            f[tx][ty]=1;
            q.push({{tx,ty},t.y+1});
        }
    }
    return -1;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&ex,&ey);
    printf("%d",bfs(sx,sy));
    return 0;
}