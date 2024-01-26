#include <iostream>

using namespace std;

// sort 1 array
int partition(int a[], int start, int end) {
    // i = pivotIndex, j = progress, Lomuto partitioning
    int i = start;
    int pivot = a[end];
    for(int j=start; j<end; j++)
        if(a[j] < pivot) {
            // swap a[i] and a[j]
            int temp = a[j];
            a[j] = a[i]; a[i] = temp;
            i++;
        }
    // swap pivot, a[end] with a[i]
    int temp = a[end];
    a[end] = a[i]; a[i] = temp;
    // return pivot index
    return i;
}

void quicksort(int a[], int start, int end) {
    if(start >= end)
        return;
    int index = partition(a, start, end);
    quicksort(a, start, index-1);
    quicksort(a, index+1, end);
    
}

// sort 2 arrays, front as ref
int partition_2(int a[], int b[], int start, int end) {
    // i = pivotIndex, j = progress, Lomuto partitioning
    int i = start;
    int pivot = a[end];
    for(int j=start; j<end; j++)
        if(a[j] < pivot) {
            // swap a[i] and a[j]
            int temp1 = a[j];
            a[j] = a[i]; a[i] = temp1;
            // swap b[i] and b[j]
            int temp2 = b[j];
            b[j] = b[i]; b[i] = temp2;
            i++;
        }
    // swap pivot, a[end] with a[i]
    int temp1 = a[end];
    a[end] = a[i]; a[i] = temp1;
    // b[end] with b[i]
    int temp2 = b[end];
    b[end] = b[i]; b[i] = temp2;
    // return pivot index
    return i;
}

void quicksort_2(int a[], int b[], int start, int end) {
    if(start >= end)
        return;
    int index = partition_2(a, b, start, end);
    quicksort_2(a, b, start, index-1);
    quicksort_2(a, b, index+1, end);
    
}

void solve() {
    int n; cin >> n;
    int k; cin >> k; // useless
    int* a = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        cin >> a[i];
    int* b = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        cin >> b[i];
    int* ref = (int*)malloc(n*sizeof(int));
    // setup ref
    for(int i=0; i<n; i++)
        ref[i] = i;
    // sort B
    quicksort(b, 0, n-1);
    // sort A-ref
    quicksort_2(a, ref, 0, n-1);
    // sort ref-B
    quicksort_2(ref, b, 0, n-1);
    // output
    for(int i=0; i<n; i++)
        cout << b[i] << ' ';
    cout << endl;
    
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++)
        solve();
    
    return 0;
}