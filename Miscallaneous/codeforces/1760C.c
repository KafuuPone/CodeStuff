#include <stdio.h>

void solve(void);

int main(void)
{
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();

    return 0;
}

void solve(void)
{
    int n;
    scanf("%d", &n);

    int arr[n], i;
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int max, max_2, max_i;
    max = max_2 = 0;
    for(i=0; i<n; i++)
        if(arr[i] >= max)
        {
            max = arr[i];
            max_i = i;
        }
    for(i=0; i<n; i++)
        if(i!=max_i && arr[i] >= max_2)
            max_2 = arr[i];

    for(i=0; i<n; i++)
        printf("%d ", arr[i]-(i==max_i?max_2:max));
    printf("\n");
}
