#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld", &n, &m);
    m += n - 1;
    printf("%lld\n", (m/7)*11665+min(m%7,5LL)*2333-min(n-1,5LL)*2333);
    return 0;
}