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
    int n, output = 1;
    scanf("%d", &n);
    int arr1[n], i;
    for(i=0; i<n; i++)
        scanf("%d", &arr1[i]);
    char arr2[n];
    getchar();
    for(i=0; i<n; i++)
        scanf("%c", &arr2[i]);

    char arr[51];
    for(i=0; i<n; i++)
        arr[arr1[i]] = arr2[i];

    for(i=0; i<n; i++)
        if(arr[arr1[i]] != arr2[i])
        {
            output = 0;
            break;
        }

    printf("%s\n", output?"YES":"NO");

}
