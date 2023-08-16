#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool fun(int x)
{
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n - i; j++)
            if (fun(i) && fun(j) && fun(n - i - j))
            {
                printf("%d %d %d\n",i,j,n-i-j);
                exit(0);
            }
    return 0;
}