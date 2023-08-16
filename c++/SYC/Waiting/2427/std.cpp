#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
int x[1005],y[1005],w[1005];
int dp[1005][305][305];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&x[i],&y[i],&w[i]);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0] = 0;
    for (int i=1;i<=n;i++)
        for (int j=x[i];j>=0;j--)
            for (int k=y[i];k>=0;k--)
                dp[i][j][k] = min(min(min(dp[i-1][j][k],dp[i-1][x[i]-j][y[i]-k]+w[i]),dp[i][j+1][k]),dp[i][j][k+1])
                ,printf("%d %d %d\n",i,j,k);
    printf("%d\n",dp[n][a][b]);
    return 0;
}