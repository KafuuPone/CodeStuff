#include <stdio.h>

void mergearr(int n1, int n2, const int arr1[], const int arr2[], int arrout[]) {
    int i, j, index; i = j = index = 0;
    while(i<n1 || j<n2) {
        if(i>=n1) {
            arrout[index] = arr2[j];
            j++;
        }
        else if(j>=n2) {
            arrout[index] = arr1[i];
            i++;
        }
        else if(arr2[j] <= arr1[i]) {
            arrout[index] = arr2[j];
            j++;
        }
        else {
            arrout[index] = arr1[i];
            i++;
        }
        index++;
    }
}

void mergesort(int n, int arr[]) {
    if(n > 1) {
        int n1 = n/2, n2 = n-n1;
        int temp1[n1], temp2[n2];
        int i = 0, j;
        for(j=0; j<n1; j++, i++) temp1[j] = arr[i];
        for(j=0; j<n2; j++, i++) temp2[j] = arr[i];
        mergesort(n1, temp1);
        mergesort(n2, temp2);
        mergearr(n1, n2, temp1, temp2, arr);
    }
}

int main() {
    int a[20] = {1, 7, 3, 5, 9, 47, 23, 89, 34, 67, 11, 4, 2, 0, 6, 1, 7, 3, 2, 13};
    mergesort(20, a);
    int i;
    for(i=0; i<20; i++) printf("%d ", a[i]);
    return 0;
}