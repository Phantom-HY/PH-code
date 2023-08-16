#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;
bool f[505];
void Game()
{
    memset(f, 0, sizeof f);
    queue<char> ap, bp;
    stack<char> c;
    for (int i = 0; i < a.size(); i++)
        ap.push(a[i]);
    for (int i = 0; i < b.size(); i++)
        bp.push(b[i]);
    int pos = 0;
    while (1)
    {
        bool flag = 1;
        while (flag)
        {
            pos++;
            char ac = ap.front();
            //printf("A打出：%c\n",ac);
            ap.pop(), c.push(ac);
            if (!f[ac])
                f[ac] = 1, flag = 0;
            else
            {
                ap.push(ac),c.pop();
                while (!c.empty())
                {
                    char u = c.top();
                    //printf("A回收：%c\n", u);
                    c.pop(), ap.push(u);
                    f[u] = 0;
                    if (u == ac)
                        break;
                }
            }
            if (ap.empty())
                break;
        }
        if (ap.empty())
            break;
        flag = 1;
        while (flag)
        {
            pos++;
            char bc = bp.front();
            //printf("B打出：%c\n", bc);
            bp.pop(), c.push(bc);
            if (!f[bc])
                f[bc] = 1, flag = 0;
            else
            {
                bp.push(bc), c.pop();
                while (!c.empty())
                {
                    char u = c.top();
                    //printf("B回收：%c\n", u);
                    f[u] = 0;
                    c.pop(), bp.push(u);
                    if (u == bc)
                        break;
                }
            }
            if (bp.empty())
                break;
        }
        if (bp.empty())
            break;
        if (pos > 1000)
        {
            printf("no solution\n");
            return;
        }
    }
    if (!ap.empty())
        while (!ap.empty())
            printf("%c", ap.front()), ap.pop();
    else
        while (!bp.empty())
            printf("%c", bp.front()), bp.pop();
    puts("");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while (cin >> a >> b)
    {
        Game();
    }
    return 0;
}