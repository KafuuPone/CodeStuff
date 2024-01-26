#include <stdio.h>

void solve(void);
int coprime(int, int);

int main(void)
{
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++)
        solve();

    return 0;
}

void solve()
{
    int n, output = -1;
    scanf("%d", &n);
    int arr[n], i, j;
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for(i=n, j=n; j>0; i++, j--)
    {
        if(i>j)
        {
            i = i+j-n-1;
            j = n;
        }
        while(i<=0)
        {
            i++;
            j--;
        }
        if(coprime(arr[i-1], arr[j-1]))
        {
            output = i+j;
            break;
        }
    }
    printf("%d\n", output);
}

int coprime(int a, int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while(a%b)
    {
        int temp = a;
        a = b;
        b = temp%b;
    }
    if(b == 1)
        return 1;
    else
        return 0;
}
