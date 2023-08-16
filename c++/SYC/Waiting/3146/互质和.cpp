#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        if (__gcd(i,n)==1)
            ans+=i,ans%=1000000007;
    printf("%lld",ans);
    return 0;
}