#include <stdio.h>

int main(void)
{
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        int n, j, k, output = 0;
        scanf("%d", &n);
        int arr[n];
        for(j=0; j<n; j++)
            scanf("%d", &arr[j]);
        for(j=0; j<n-1; j++)
        {
            for(k=j+1; k<n; k++)
                if(arr[j]==arr[k])
                {
                    output = 1;
                    break;
                }
            if(output)
                break;
        }
        if(n==1)
            output = 0;
        printf("%s", output?"NO\n":"YES\n");
    }

    return 0;
}
