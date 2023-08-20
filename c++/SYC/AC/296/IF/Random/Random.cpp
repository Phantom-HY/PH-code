#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    srand(time(NULL));
    int len = rand() % 10 + 1;
    int x, y;
    x = y = len;
    int cnt = 0;
    for (int i = 1; i <= 2 * len; i++)
    {
        if (x != 0 && y != 0)
        {
            int t = rand() % 2;
            if (t == 1 && cnt != 0)
                printf(")"), y--, cnt--;
            else
                printf("("), x--, cnt++;
        }
        else if (x == 0)
        {
            printf(")");
            y--;
        }
        else
        {
            printf("(");
            x--;
        }
    }
    return 0;
}