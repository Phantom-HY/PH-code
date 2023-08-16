#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int main(){
    srand(time(0));
    n=rand()%100000+1,m=rand()%100000+1;
    printf("%d %d\n",n,m);
    for (int i=1;i<=n;i++)
        printf("%d %d\n",rand()%10+1,rand()%10+1);
    return 0;
}