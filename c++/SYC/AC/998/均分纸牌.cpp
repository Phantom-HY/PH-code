#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[105],sum,ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i),sum+=a[i];
    sum/=n;
    for (int i=1;i<=n;i++)
        if (a[i]-sum)
            a[i+1]+=a[i]-sum,ans++;
    printf("%d",ans);
    return 0;
}