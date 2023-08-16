#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int l,r;
ll a[5000005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    for (int i=1;i<=5e6;i++)
        a[i]=i^a[i-1];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        printf("%lld\n",a[r]^a[l-1]);
    }
    return 0;
}