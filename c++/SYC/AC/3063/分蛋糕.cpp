#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &n);
    if (n % 2 == 0)
    {
        printf("%lld", n / 2);
    }
    else if (n==1)
    {
        printf("0");
    }
    else
    {
        printf("%lld", n);
    }
    return 0;
}