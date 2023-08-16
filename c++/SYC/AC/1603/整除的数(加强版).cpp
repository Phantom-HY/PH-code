#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,a,b;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld",&T);
    while (T--)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",a/b);
    }
    return 0;
}