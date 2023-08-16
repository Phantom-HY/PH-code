#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld",&n);
    n*=(n+1);
    printf("%lld",n/2-1);
    return 0;
}