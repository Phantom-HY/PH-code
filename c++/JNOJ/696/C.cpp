#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vl[1000005],l[1000005];
int n;
int vis[1000005];
int ans;
void fun(int x,int step)
{
    if (x == n+1)
    {
        ans = max(ans,step);
        return;
    }
    int fl = vis[l[x]],f = vis[x];
    fun(x+1,step);
    if (fl!=1&&f==0)
    {
        vis[l[x]] = -1;
        vis[x] = 1;
        fun(x+1,step+vl[x]);
        vis[l[x]] = fl;
        vis[x] = f;
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i = 1;i<=n;i++)
        scanf("%d%d",&vl[i],&l[i]);
    fun(1,0);
    printf("%d",ans);
    return 0;
}