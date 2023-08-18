#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    srand(time(NULL));
    int n, m;
    n = rand() % 20+1;
    m = rand() % 20+1;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", rand() % 100 + 1, rand() % 100 + 1);
    }
    return 0;
}