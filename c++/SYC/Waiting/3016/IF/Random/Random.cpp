#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pow(int x, int y)
{
    int ans = 1;
    while (y--)
        ans *= x;
    return ans;
}
int main()
{
    srand(time(NULL));
    int n, k;
    n = 20;
    k = rand() % 100;
    printf("%d %d\n", n, k);
    for (int i = 1; i <= n; i++)
        printf("%d ", rand() % 1000);
    return 0;
}