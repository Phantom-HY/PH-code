#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
    srand(time(0));
    n = rand() % 20;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
    {
        int x = rand() % n + 1;
        printf("%d ", x);
    }
    return 0;
}