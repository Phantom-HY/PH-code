#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char x;
int n;
stack<int> c;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while (scanf("%c", &x), x != '@')
    {
        if (x == '+')
        {
            int a, b;
            a = c.top(), c.pop();
            b = c.top(), c.pop();
            c.push(a + b);
        }
        else if (x == '-')
        {
            int a, b;
            a = c.top(), c.pop();
            b = c.top(), c.pop();
            c.push(b - a);
        }
        else if (x == '/')
        {
            int a, b;
            a = c.top(), c.pop();
            b = c.top(), c.pop();
            c.push(b / a);
        }
        else if (x == '*')
        {
            int a, b;
            a = c.top(), c.pop();
            b = c.top(), c.pop();
            c.push(a * b);
        }
        else if (x == '.')
            c.push(n), n = 0;
        else
            n *= 10, n += x - '0';
    }
    printf("%d", c.top());
    return 0;
}