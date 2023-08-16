#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int nu[100005],c[100005];
int ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",nu+i);
    for (int i=1;i<=n;i++)
        scanf("%d",c+i);
    for (int i=1;i<=n;i++)
        for (int j=i+2;j<=n;j+=2)
        {
            if (c[i]==c[j])
                ans+=(i+j)*(nu[i]+nu[j]),ans%=1007;
        }
    printf("%d",ans);
    return 0;
}