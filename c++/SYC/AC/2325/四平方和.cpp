#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=0;i*i<=n;i++)
        for (int j=i;j*j+i*i<=n;j++)
            for (int y=j;y*y+j*j+i*i<=n;y++)
            {
                int x=sqrt(n-(y*y+j*j+i*i));
                if (y*y+j*j+i*i+x*x==n)
                {
                    printf("%d %d %d %d\n",i,j,y,x);
                    exit(0);
                }
            }
    return 0;
}