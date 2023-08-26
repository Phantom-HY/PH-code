#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0, cnt = 1, sum = 0;; i++, cnt *= 2)
    {
        sum += cnt;
        if (sum >= n)
            printf("%d\n",i+1),exit(0);
    }
    return 0;
}