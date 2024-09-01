#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int cnt = 2000;
int main()
{
    srand(time(NULL));
    n = rand() % 20;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
    {
        int x = rand() % 20 + 1;
        while (x > cnt)
            x = rand() % 20 + 1;
        printf("%d ", x);
    }
    return 0;
}