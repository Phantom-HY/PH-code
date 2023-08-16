#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[100005];
ll ans;
ll max(ll a,ll b)
{
    return a>b?a:b;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i),a[i]+=a[i-1];
    for (int i=1;i+m-1<=n;i++)
        ans=max(ans,a[i+m-1]-a[i-1]);
    printf("%lld",ans);
    return 0;
}