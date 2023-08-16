#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int d[100005],u[100005];
int sumd[100005],sumu[100005];
int ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]),sumd[i]=sumd[i-1]+d[i];
    for (int i=1;i<=n;i++)
        scanf("%d",&u[i]),sumu[i]=sumu[i-1]+u[i];
    for (int i=2;i<n;i++)
        for (int j=i;j<n;j++)
            for (int x=i-1;x>=1;x--)
                for (int y=j+1;y<=n;y++)
                    ans=max(ans,sumu[y]-sumu[x-1]+sumd[j]-sumd[i-1]);
    printf("%d\n",ans);
    return 0;
}