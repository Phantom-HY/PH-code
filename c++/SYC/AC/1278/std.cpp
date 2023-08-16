#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[100005], n, m;
vector<int>sum[100005];
void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i;
}
int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    init();
    for (int i = 0; i < m; i++)
    {
        int c,x, y;
        scanf("%d%d%d",&c,&x,&y);
        if (c == 0)
            merge(x, y);
        else 
            sum[x].push_back(y),sum[y].push_back(x);
    }
    for (int i=1;i<=n;i++)
        for (int j=0;j<sum[i].size();j++)
            for (int x=0;x<sum[sum[i][j]].size();x++)
                merge(i, sum[sum[i][j]][x]);
    int ans=0;
    for (int i=1;i<=n;i++)
        ans+=find(i)==i;
    printf("%d\n",ans);
    return 0;
}