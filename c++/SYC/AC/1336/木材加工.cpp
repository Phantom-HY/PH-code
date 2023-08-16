#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[100005];
ll ans;
bool check(int x)
{
    ll cnt=0;
    for (int i=1;i<=n;i++)
        cnt+=a[i]/x;
    return cnt>=k;
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
    }
    int l=1,r=100000000;
    while(l<=r)
    {
        int mid=l+r>>1;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}