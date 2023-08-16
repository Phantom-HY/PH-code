#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d;
int p[100005];
ll ans;
int s(int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (p[mid] <= x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;i++)
        scanf("%d",p+i);
    sort(p+1,p+1+n);
    for (int i=1;i<n;i++)
        ans+=s(i+1,n,p[i]+d)-i;
    printf("%lld",ans);
    return 0;
}