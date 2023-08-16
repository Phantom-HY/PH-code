#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[10005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    while(k--&&next_permutation(a+1,a+1+n));
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}