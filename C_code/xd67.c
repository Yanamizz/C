#include <stdio.h>

int main()
{
    int n , num , x=0;
    scanf("%d %d", &n, &num);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            printf("%d ", i);
            x++;
        }
    }
    if (x == 0)
    {
        printf("-1");
    }
    return 0;
}