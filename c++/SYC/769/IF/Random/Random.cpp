#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    srand(time(NULL));
    int n, m;
    n = rand() % 50+1;
    m = rand() % 50+1;
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", rand() % 100 + 1, rand() % 100 + 1);
    }
    return 0;
}