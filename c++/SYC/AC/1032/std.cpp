#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
int dp[100005];
int ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    memset(dp,-0x3f,sizeof dp);
    for (int i=1;i<=n;i++)
        dp[i]=max(dp[i-1]+a[i],a[i]),ans=max(ans,dp[i]);
    printf("%d", ans);
    return 0;
}