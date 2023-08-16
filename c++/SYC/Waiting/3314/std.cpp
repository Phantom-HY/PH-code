#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll cnt;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld",&n,&m);
    cnt=n;
    for (int i=1;i<=n;i++)
    {
        cnt=(cnt+m)%i;
    }
    printf("%lld\n",cnt+1);
    return 0;
}