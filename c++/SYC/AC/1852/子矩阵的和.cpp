#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll a[1005][1005];
int x,b,c,d;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]),
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    while(k--)
    {
        scanf("%d%d%d%d",&x,&b,&c,&d);
        printf("%lld\n",a[c][d]-a[x-1][d]-a[c][b-1]+a[x-1][b-1]);
    }
    return 0;
}