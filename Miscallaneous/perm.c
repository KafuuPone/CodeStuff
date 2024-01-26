#include <stdio.h>

int main(void) {
    int n, k; scanf("%d %d", &n, &k); //input <= 25
    int data[n] = {0};
    int count = 0;//count of perms
    while(1) {
        //generation
        int carry = 1, i;
        for(i=0; i<n; i++) {
            data[i] += carry;
            if(data[i] == 2) {
                data[i] = 0;
                carry = 1;
            }
            else {
                carry = 0;
                break;
            }
        }
        //checking
        for(i=0; i<=n-k; i++) {
            int hit = 1, j;
            for(j=0; j<k; j++) {
                if(data[i+j] == 0) {
                    hit = 0;
                    break;
                }
            }
            if(hit) {
                // for(i=0; i<n; i++)
                //     printf("%d", data[i]);
                // printf("\n");
                count++;
                break;
            }
        }
        //exit loop
        if(carry == 1)
            break;
    }
    printf("%d", count);
    return 0;
}