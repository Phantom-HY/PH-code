#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l_1,l_2,r_1,r_2;
ll a[10005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d%d%d",&n,&l_1,&r_1,&l_2,&r_2);
    for (int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+l_1,a+r_1+1);
    sort(a+l_2,a+r_2+1,greater<>());
    for (int i=1;i<=n;i++)
        printf("%lld ",a[i]);
    return 0;
}