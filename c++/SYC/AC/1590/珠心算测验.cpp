#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[10005],ans;
// unordered_map<int,bool>m;
bool m[5000005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld",&n);
    for (int i=1;i<=n;i++)  
        scanf("%lld",a+i),m[a[i]]=1;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            ans+=m[a[i]+a[j]],m[a[i]+a[j]]=0;
    printf("%lld",ans);
    return 0;
}