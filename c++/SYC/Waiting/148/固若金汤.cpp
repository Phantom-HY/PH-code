#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[200005];
ll sum[200005];
ll ans_1,ans_2;
ll max(ll a,ll b)
{
    return a>b?a:b;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        sum[i]=sum[i-1]+a[i];
        if (i<=k)
        {
            ans_2=max(sum[i],ans_2);
        }
        else if (i==n)
        {
            ans_1=max(sum[i]-sum[i-k],ans_1);
        }
        else
        {
            ans_1=max(sum[i]-sum[i-k],ans_1);
            ans_2=max(sum[i]-sum[i-k],ans_2);
        }
    }
    printf("%lld %lld",ans_2,ans_1);
    return 0;
}