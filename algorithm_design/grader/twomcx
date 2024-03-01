#include <stdio.h>
#include <stdlib.h>
int i, n, q[] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};
int o(int s, int d, int c)
{
    if (s == 0)
        return c;
    if (d <= 0)
        return 1111111111;
    int l = s / q[d - 1], u = s >= 0 ? l + 1 : l - 1;
    l = o(s - l * q[d - 1], d - 1, c + abs(l) * d);
    u = o(s - u * q[d - 1], d - 1, c + abs(u) * d);
    return l < u ? l : u;
}
int main()
{
    scanf("%d", &n);
    for (i = 0; n >= q[i]; ++i)
        ;
    printf("%d\n", o(n, i + 1, 0));
}
