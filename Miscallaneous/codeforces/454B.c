#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n], i;
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    int dec=0, dec_i=n-1;
    for(i=0; i<n; i++)
        if(a[i]>a[(i==n-1) ? 0:i+1])
        {
            dec++;
            dec_i = i;
        }

    printf("%d", (dec>1) ? -1:n-1-dec_i);
}
