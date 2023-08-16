#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
ll a[200005],x;
ll sum[200005];
int qi(ll x)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        if (a[mid]>=x)
            r=mid-1;
        else
            l=mid+1;
    }
    return l;
}
int h(ll x)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        if (a[mid]<=x)
            l=mid+1;
        else
            r=mid-1;
    }
    return r;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    while (q--)
    {
        scanf("%lld",&x);
        int l=qi(x),r=h(x);
        if (a[l]!=x)
        {
            printf("%lld\n",abs((x*(n-l+1))-(sum[n]-sum[l-1]))+abs((x*(l-1))-sum[l-1]));
        }
        else
        {
            printf("%lld\n",abs((x*(n-r))-(sum[n]-sum[r]))+abs((x*(l-1))-sum[l-1]));
        }
    }
    return 0;
}