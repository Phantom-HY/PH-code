#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[3], ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);
    sort(a,a+3);
    if (a[2]>=a[0]+a[1])
        ans=a[0]+a[1];
    else 
        ans=(a[0]+a[1]+a[2])/2;
    printf("%lld",ans);
    return 0;
}