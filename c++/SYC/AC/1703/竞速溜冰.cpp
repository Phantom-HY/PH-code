#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c,ans,cnt;
priority_queue<int>a;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&m,&c);
    for (int i=1;i<=n;i++)
        a.push(m);
    while (c>0)
    {
        ans++;
        int x=a.top();
        a.pop();
        int num=int(sqrt(x-cnt));
        c-=num;
        cnt+=num;
        a.push(x-num*(num-1));
    }
    printf("%d",ans);
    return 0;
}