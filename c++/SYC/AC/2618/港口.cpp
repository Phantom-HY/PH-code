#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int w[100005];
int d[100005];
ll cnt[3];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",w+i),d[i]=w[i]-w[i-1];
    for (int i=2;i<=n;i++)
        if (d[i]>0)cnt[1]+=d[i];
        else cnt[2]-=d[i];
    printf("%lld",max(cnt[1],cnt[2]));
    return 0;
}