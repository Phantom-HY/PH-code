#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,ans;
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for (ll w=1;w<=m;w++)
    {
        ll h=k%w==0?k/w:k/w+1;
        if (h>n)continue;
        ans=max(ans,((n/h)-1)+((m/w)-1));
    }
    printf("%lld",ans);
    return 0;
}