#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i),a[i]+=a[i-1];
    int t;
    scanf("%d",&t);
    int l,r;
    while(t--)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",a[r]-a[l-1]);
    }
    return 0;
}