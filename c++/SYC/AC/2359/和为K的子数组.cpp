#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll a[200005];
int ans;
unordered_map<long long,int>t;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        a[i]+=a[i-1];
        ans+=t[a[i]-k];
        t[a[i]]++;
    }
    printf("%d",ans);
    return 0;
}