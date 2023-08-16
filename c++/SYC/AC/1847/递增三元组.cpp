#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005],b[100005],c[100005],n;
ll ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    for (int i=1;i<=n;i++)
        scanf("%d",b+i);
    for (int i=1;i<=n;i++)
        scanf("%d",c+i);
    sort(a+1,a+1+n);
    sort(c+1,c+1+n);
    for (int i=1;i<=n;i++)
    {
        int x=lower_bound(a+1,a+1+n,b[i])-a,y=upper_bound(c+1,c+1+n,b[i])-c;
        if (a[y]>=b[i])x--;
        if (c[y]>b[i])y=n-y+1;
        else y=0;
        //printf("%d %d\n",x,n-y+1);
        ans+=x*y;
    }
    printf("%lld",ans);
    return 0;
}