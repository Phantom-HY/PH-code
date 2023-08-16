#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x;
char c;
stack<int> a;
stack<char> b;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x), a.push(x);
    for (int i = 1; i < n; i++)
    {
        cin >> c;
        b.push(c);
    }
    while (!b.empty())
    {
        char z = b.top();
        b.pop();
        int x, y;
        x = a.top();
        a.pop();
        y = a.top();
        a.pop();
        if (x == 0 && z == '/')
        {
            printf("ERROR: %d/0", y);
            exit(0);
        }
        if (z == '+')
            a.push(y + x);
        if (z == '-')
            a.push(y - x);
        if (z == '*')
            a.push(y * x);
        if (z == '/')
            a.push(y / x);
    }
    printf("%d", a.top());
    return 0;
}