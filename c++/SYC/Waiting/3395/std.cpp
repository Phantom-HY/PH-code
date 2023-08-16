#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, m;
char s[15];
int ans[1005][505][505];
int len = 1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &k, &m);
    for (int i=1;i<=m;i++)
    {
        scanf("%s",s);
        if (s[0]=='D')
        {
            int i,j,x,y,c;
            scanf("%d%d%d%d%d",&c,&i,&j,&x,&y);
            i++,j++,x++,y++;
            for (int e=i;e<=x;e++)
                for (int f=j+(e-i)%2;f<=y;f+=2)
                    ans[len][e][f] = c;
        }
        else if (s[0]=='S')
        {
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    ans[len+1][i][j]=ans[len][i][j];
            len++;
        }else
        {
            int x;
            scanf("%d",&x);
            len=x;
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            printf("%d%c",ans[len][i][j]," \n"[j==n]);
    return 0;
}