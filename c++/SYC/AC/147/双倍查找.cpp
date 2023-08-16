#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
ll ans;
bool s(int l,int r,int c)
{
    while(l<=r)
    {
        int mid=l+r>>1;
        if (a[mid]==c)
            return 1;
        if (a[mid]<c)
            l=mid+1;
        else 
            r=mid-1;
    }
    return 0;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
        ans+=s(1,n,a[i]*2);
    printf("%lld",ans);
    return 0;
}