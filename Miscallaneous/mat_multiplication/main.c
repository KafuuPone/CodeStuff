#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50 // number of times to test per test

void test() {
    // input parameters
    int n, x, y, m;
    scanf("%d %d %d %d", &n, &x, &y, &m);

    // input matrix
    int mat_a[n*x], mat_b[y*m], mat_c[n*m];
    for(int i=0; i<n*x; i++)
        scanf("%d", &(mat_a[i]));
    for(int i=0; i<y*m; i++)
        scanf("%d", &(mat_b[i]));
    for(int i=0; i<n*m; i++)
        scanf("%d", &(mat_c[i]));

    if(x != y) {
        printf("Inner matrix dimensions must agree\n");
        return;
    }

    for(int count=0; count<N; count++) {
        // generate random column vector v
        int mat_v[m];
        for(int i=0; i<m; i++)
            mat_v[i] = rand()%2;

        // multiply c*x and a(b*x) col 0~n-1 and compare, if different immediately output "WA" and exit func
        int mat_tempv[x];
        int* a_index = mat_a;
        int* b_index = mat_b;
        int* c_index = mat_c;
        for(int i=0; i<x; i++) {
            //calculating b*x col j:0~x-1
            int sum_bx = 0;
            for(int j=0; j<m; j++) {
                if(mat_v[j] != 0)
                    sum_bx += *(b_index);
                b_index++;
            }
            mat_tempv[i] = sum_bx;
        }
        for(int i=0; i<n; i++) {
            // calculating c*x col i:0~n-1
            int sum = 0;
            for(int j=0; j<m; j++) {
                if(mat_v[j] != 0)
                    sum += *(c_index);
                c_index++;
            }
            // calculating c*x-a*(b*x) col i:0~n-1
            for(int j=0; j<x; j++) {
                sum -= *(a_index)*mat_tempv[j];
                a_index++;
            }

            // check if final vector, element i is equal
            if(sum != 0) {
                printf("WA\n");
                return;
            }
        }        
    }
    // everything is correct :)
    printf("AC\n");
    return;
}

int main() {
    // set random seed
    srand(time(0));

    // num of test cases
    int tc; scanf("%d", &tc);

    // run test cases
    for(int i=0; i<tc; i++)
        test();

    return 0;
}