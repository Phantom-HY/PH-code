#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a%b);
} 
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll A,B,n,x;
bool check(ll mid)
{
    return (mid/A+mid/B-mid/x)>=n;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld%lld",&A,&B,&n);
    ll l,r;
    x=lcm(A,B);
    l=1,r=1e18;
    ll ans;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%lld",ans);
    return 0;
}