#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>ans;
int n,m,t,a[105][105],col[205],tp;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&m,&t);
    for (int i=1;i<=n+m;i++)scanf("%d",col+i),tp=max(tp,col[i]);
    if (tp==1)
    {
        int o=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]),o=max(o,a[i][j]);
        if (o!=1)printf("0\n");
        else 
        {
            printf("%d\n",m);
            for (int i=1;i<=m;i++)printf("%d ",i);
            puts("");
        }
    }
    return 0;
}