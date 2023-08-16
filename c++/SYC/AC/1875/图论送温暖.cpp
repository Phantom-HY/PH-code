#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[1005][1005];
int cnt,sum,ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]),cnt+=i==m&&a[i][j],sum+=j==m&&a[i][j],ans+=a[i][j]!=0;
    printf("%d %d %d\n%d",m,cnt,sum,ans);
    return 0;
}