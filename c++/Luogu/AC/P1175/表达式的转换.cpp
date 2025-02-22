#include <bits/stdc++.h>
using namespace std;
using namespace std;
typedef long long ll;
stack<char> dat, op;
stack<int> num, dat2;
int check(char c)
{
    switch (c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return 0;
    case ')':
        return 0;
    default:
        return -1;
    }
}
int js(int x, int y, char t)
{
    switch (t)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '^':
        return pow(x, y);
    default:
        return -0x3f3f3f3f;
    }
}
void change(string s)
{
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
            dat.push(s[i]);
        else if (s[i] == '(')
            op.push(s[i]);
        else if (s[i] == ')')
        {
            char t = op.top();
            while (t != '(')
            {
                op.pop();
                dat.push(t);
                t = op.top();
            }
            op.pop();
        }
        else if (check(s[i]) >= 1 && check(s[i]) <= 3)
        {
            if (!op.empty())
            {
                char t = op.top();
                while (!op.empty() && check(s[i]) <= check(t))
                {
                    if (check(s[i]) == check(t) && s[i] == '^')
                        break;
                    op.pop();
                    dat.push(t);
                    if (!op.empty())
                        t = op.top();
                }
            }
            op.push(s[i]);
        }
    }
    while (!op.empty())
    {
        char t = op.top();
        op.pop();
        dat.push(t);
    }
    while (!dat.empty())
    {
        char t = dat.top();
        dat.pop();
        op.push(t);
    }
    while (!op.empty())
    {
        char t = op.top();
        cout << t << ' ';
        op.pop();
        dat.push(t);
    }
    cout << endl;
}
void calc()
{
    while (!dat.empty())
    {
        char t = dat.top();
        dat.pop();
        op.push(t);
    }
    while (!op.empty())
    {
        char t = op.top();
        op.pop();
        if (isdigit(t))
            num.push(t - '0');
        else
        {
            int x = num.top();
            num.pop();
            int y = num.top();
            num.pop();
            num.push(js(y, x, t));
            while (!num.empty())
            {
                int t = num.top();
                num.pop();
                dat2.push(t);
            }
            while (!dat2.empty())
            {
                int t = dat2.top();
                cout << t << ' ';
                dat2.pop();
                num.push(t);
            }
            while (!op.empty())
            {
                char t = op.top();
                cout << t << ' ';
                op.pop();
                dat.push(t);
            }
            while (!dat.empty())
            {
                char t = dat.top();
                dat.pop();
                op.push(t);
            }
            cout << endl;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    string s;
    cin >> s;
    change(s);
    calc();
    return 0;
}