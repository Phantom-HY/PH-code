#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m;
ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",lcm(n,m));
    }
    return 0;
}