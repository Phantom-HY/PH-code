#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,n;
int a[100005],b[100005];
stack<int>c;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",a+i);
        for (int i=1;i<=n;i++)
            scanf("%d",b+i);
        int len=1;
        for (int i=1;i<=n;i++)
        {    
            c.push(a[i]);
            while (!c.empty()&&c.top()==b[len])
            {
                len++;
                c.pop();
            }
        }
        puts(c.empty()?"Yes":"No");
        while(!c.empty())
            c.pop();
    }
    return 0;
}