#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double fun()
{
    char s[105];
    cin >> s;
    switch (s[0])
    {
    case '+':
        return fun() + fun();
    case '-':
        return fun() - fun();
    case '*':
        return fun() * fun();
    case '/':
        return fun() / fun();
    default:
        return atof(s);
        break;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    double ans = fun();
    printf("%.4lf", ans);
    return 0;
}