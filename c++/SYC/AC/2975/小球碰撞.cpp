#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
stack<pair<int, int>> a;
stack<int> ans;
int n, x;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (a.size())
        {
            bool flag = 0;
            while (a.size())
            {
                pair<int, int> u = a.top();
                a.pop();
                // printf("%d %d\n",x,u.y);
                if (x < 0 && u.y > 0)
                {
                    if (abs(x) != abs(u.y))
                    {
                        if (abs(x) < abs(u.y))
                        {
                            a.push(u);
                            flag = 1;
                            break;
                        }
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    a.push(u);
                    break;
                }
            }
            if (flag == 0)
                a.push({i, x});
        }
        else
            a.push({i, x});
    }
    printf("%d\n", a.size());
    while (a.size())
    {
        ans.push(a.top().x), a.pop();
    }
    while (ans.size())
    {
        printf("%d ", ans.top()), ans.pop();
    }
    return 0;
}