#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct student
{
    int shengao,tc;
};
queue<student> c[5];
int n, a[5], pos, x[5][700005], y;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=a[i];j++)
            scanf("%d",&x[i][j]),pos++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= a[i]; j++)
            scanf("%d", &y),c[i].push({x[i][j],y});
    while (pos)
    {
        int cnt = 0;
        for (int i=1;i<=n;i++)
        {
            if (c[i].size()==0)continue;
            if (cnt==0)
            {
                cnt=i;
                continue;
            }
            auto f=c[i].front();
            if (f.shengao<c[cnt].front().shengao)
                cnt = i;
        }
        printf("%d ",c[cnt].front().tc),c[cnt].pop(),pos--;
    }
    return 0;
}