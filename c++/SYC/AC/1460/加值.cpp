#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
ll a[100005],f[100005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i),f[i]=a[i]-a[i-1];
    scanf("%d",&q);
    while (q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        f[l]+=1;
        f[r+1]-=1;
    }
    for (int i=1;i<=n;i++)
        f[i]+=f[i-1],printf("%d ",f[i]);
    return 0;
}