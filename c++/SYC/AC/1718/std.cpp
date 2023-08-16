#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
ll x[1000005];
ll q;
ll l,r;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld",&k);
    for (int i=1;i<=k;i++){
        scanf("%lld",&x[i]);
        x[i]^=x[i-1];
    }
    x[k+1]=0;
    scanf("%lld",&q);
    for (int i=1;i<=q;i++)
    {
        scanf("%lld%lld",&l,&r);
        l%=k+1;
        r%=k+1;
        if (l==0)
            l=k+1;
        if (r==0)
            r=k+1;
        printf("%lld\n",x[r]^x[l-1]);
    }
    return 0;
}