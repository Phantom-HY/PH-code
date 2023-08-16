#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005];
int dp[2][100005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    memset(dp, -0x3f, sizeof dp);
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
    {
        dp[0][i] = max(dp[0][i-1],dp[1][i-1]+a[i]);
        dp[1][i] = max(dp[1][i-1],-a[i]);
        // printf("%d %d\n", dp[0][i], dp[1][i]);
    }
    printf("%d\n", dp[0][n]);
    return 0;
}