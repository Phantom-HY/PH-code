#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<int,int>a[200005];
int q;
pair<int,int>x,y;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i].first),a[i].second=i;
    sort(a+1,a+1+n);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&x.second,&y.second,&x.first);
        y.first=x.first;
        auto i=lower_bound(a+1,a+1+n,x);
        auto j=upper_bound(a+1,a+1+n,y);
        if (i==a+n+1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",j-i);
        }
    }
    return 0;
}