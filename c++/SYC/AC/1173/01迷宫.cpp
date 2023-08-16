#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans[100005],x,y,f[1005][1005];
char s[1005][1005];
void dfs(int x,int y,int z,int sz)
{
    if (x<0||y>=n||x<0||y>=n||f[x][y]!=-1||s[x][y]-'0'!=z)
        return ;
    f[x][y]=sz;
    ans[sz]++;
    dfs(x-1,y,!z,sz);
    dfs(x+1,y,!z,sz);
    dfs(x,y-1,!z,sz);
    dfs(x,y+1,!z,sz);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    memset(f,-1,sizeof f);
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%s",s+i);
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        x--,y--;
        if (f[x][y]==-1)dfs(x,y,s[x][y]-'0',i);
        else ans[i]=ans[f[x][y]];
        printf("%d\n",ans[i]);
    }
    return 0;
}