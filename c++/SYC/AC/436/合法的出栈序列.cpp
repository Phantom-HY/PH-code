#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int x[25];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    while (m--)
    {
        stack<int> a;
        for (int i=1;i<=n;i++)
            scanf("%d",x+i);
        int k=1;
        for (int i=1;i<=n;i++)
        {
            a.push(i);
            while(a.size()&&a.top()==x[k])
                k++,a.pop();
        }
        if (a.size())printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}