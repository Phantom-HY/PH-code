#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[1005][1005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]),
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            printf("%lld%c",a[i][j]," \n"[j==m]);
    return 0;
}