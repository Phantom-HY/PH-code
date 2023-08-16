#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,x;
ll ans;
priority_queue<int,vector<int>,greater<int>>a;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&x),a.push(x),ans+=x;
    while (k--)
    {
        int cnt=a.top();
        a.pop();
        ans+=-2*cnt;
        a.push(-cnt);
    }
    printf("%lld",ans);
    return 0;
}