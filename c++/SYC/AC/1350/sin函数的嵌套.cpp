#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1005][1005];
int n;
void f(int k)
{
    if (k == n)
    {
        printf("sin(%d)", n);
        return;
    }
    printf("sin(%d+", k);
    f(k + 1);
    printf(")");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    f(1);
    return 0;
}