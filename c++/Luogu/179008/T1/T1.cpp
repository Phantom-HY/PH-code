#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int k;
int ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    while (k--)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        ans += (y >= x);
    }
    printf("%d",ans);
    return 0;
}