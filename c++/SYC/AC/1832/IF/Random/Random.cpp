#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    srand(time(NULL));
    int l, t, o;
    l = rand() % 100000 + 1;
    t = rand() % 30 + 1;
    o = rand() % 100000 + 1;
    printf("%d %d %d\n", l, t, o);
    while (o--)
    {
        int a, b, x;
        a = rand() % l + 1;
        b = rand() % l + 1;
        x = rand() % t + 1;
        int op = rand() % 2;
        if (a > b)
            swap(a, b);
        if (op)
            printf("C %d %d %d\n", a, b, x);
        else
            printf("P %d %d\n", a, b);
    }
    return 0;
}