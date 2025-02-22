#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b;
int n;
int x, y;
void ch(int x)
{
    if (x >= a)
        b = a, a = x;
    else if (x >= b)
        b = x;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("bamboo4.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &x, &y);
        ch(y);
        ch(x - y);
    }
    printf("%d",a+b);
    return 0;
}