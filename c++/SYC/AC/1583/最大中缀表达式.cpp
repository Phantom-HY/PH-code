#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x;
ll ans;
priority_queue<int>a;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n+m+1;i++)
        scanf("%d",&x),a.push(x);
    while (n+1)
    {
        ans+=a.top();
        a.pop();
        n--;
    }
    while(a.size())
    {
        ans-=a.top();
        a.pop();
    }
    printf("%lld",ans);
    return 0;
}