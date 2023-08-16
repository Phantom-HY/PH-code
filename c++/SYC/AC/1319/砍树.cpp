#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll k;
ll a[1000005];
ll ans;
bool check(ll x)
{
    ll cnt=0;
    for (int i=1;i<=n;i++)
        cnt+=max(0LL,a[i]-x);
    return cnt>=k;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
    }
    int l=1,r=1000000000;
    while(l<=r)
    {
        int mid=l+r>>1;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}