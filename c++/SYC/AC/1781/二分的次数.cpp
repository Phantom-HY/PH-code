#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x;
ll a[10005];
int ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%lld",&n,&x);
    for (int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+1+n);
    ll l,r;
    l=1,r=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        ans++;
        if (a[mid]==x)
            break;
        if (a[mid]<x)
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d",ans);
    return 0;
}