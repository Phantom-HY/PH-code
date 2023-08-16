#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
int a[105][105],r[105];
bool v[105];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    scanf("%d",&t);
    while(t--)
    {
        for (int i=1;i<=100;i++)v[i]=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++)
        {
            char q;
            for (int j=1;j<=n;j++)cin>>q,a[i][j]=q-'0';
            scanf("%d",r+i);
        }
        int cnt=m,op,aa,bb=0,h,f,b=1;
        while(cnt)
        {
            aa=h=0;
            for (int i=1;i<=n;i++)
            {
                for (int u=0;u<=1;u++)
                {
                    f=1,op=-1;
                    for (int k=1;k<=m;k++)
                    {
                        if (a[k][i]!=u||v[k])continue;
                        if (r[k]!=op&&~op)
                        {
                            f=0;
                            break;
                        }
                        op=r[k];
                    }
                    if (f&&~op)
                    {
                        aa=i,bb=u;
                        break;
                    }
                }
                if (aa)break;
            }
            if (aa)
            {
                for (int i=1;i<=m;i++)
                    if (a[i][aa]==bb&&!v[i])
                        v[i]=1,h++;
                cnt-=h;
            }
            else
            {
                b=0;
                break;
            }
        }
        printf("%s\n",b?"OK":"LIE");
    }
    return 0;
}