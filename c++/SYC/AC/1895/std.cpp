#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    printf("%lld\n",ll(1LL<<n));
    return 0;
}