#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,s;
int a,b;
pair<int,int>p[5005];
int ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d%d",&n,&s,&a,&b);
    a+=b;
    for (int i=1;i<=n;i++)
        scanf("%d%d",&p[i].second,&p[i].first);
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++)
    {
        if (p[i].second<=a)
            if (s-p[i].first>=0)
            {
                ans++;
                s-=p[i].first;
            }
    }
    printf("%d",ans);
    return 0;
}