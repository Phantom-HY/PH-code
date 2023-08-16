#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod =1e9+7;
int n,m;
int a[100005],b[100005];
ll ans;
void dfs(int l)
{
    if (l==n+1)
    {
        // for (int i=1;i<=n;i++)
        //     printf("%d ",a[i]);
        // printf("\n");
        // for (int i=1;i<=n;i++)
        //     printf("%d ",b[i]);
        // printf("\n");
        ans++;
        ans%=mod;
        return;
    }
    for (int i=a[l-1];i<=m;i++)
    {
        for (int j=b[l-1];j>=0;j--)
        {
            if (i<=j)
            {
                a[l]=i;
                b[l]=j;
                dfs(l+1);
            }
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    b[0]=m,a[0]=1;
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}