#include <iostream>

using namespace std;

int partition(int a[], int start, int end) {
    // i = pivotIndex, j = progress, Lomuto partitioning
    int i = start;
    int pivot = a[end];
    for(int j=start; j<end; j++)
        if(a[j] <= pivot) {
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

int main() {
    int n; cin >> n;
    int* a = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        cin >> a[i];
    quicksort(a, 0, n-1);
    // output
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << endl;
}