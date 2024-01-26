#include <iostream>

using namespace std;

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
    // bubble sort B
    bool notsorted = true;
    while(notsorted) {
        notsorted = false;
        for(int i=0; i<n-1; i++) {
            if(b[i] > b[i+1]) {
                int temp = b[i+1];
                b[i+1] = b[i]; b[i] = temp;
                notsorted = true;
            }
        }
    }
    // bubble sort A-ref
    notsorted = true;
    while(notsorted) {
        notsorted = false;
        for(int i=0; i<n-1; i++) {
            if(a[i] > a[i+1]) {
                int temp1 = a[i+1];
                a[i+1] = a[i]; a[i] = temp1;
                int temp2 = ref[i+1];
                ref[i+1] = ref[i]; ref[i] = temp2;
                notsorted = true;
            }
        }
    }
    // bubble sort ref-B
    notsorted = true;
    while(notsorted) {
        notsorted = false;
        for(int i=0; i<n-1; i++) {
            if(ref[i] > ref[i+1]) {
                int temp1 = ref[i+1];
                ref[i+1] = ref[i]; ref[i] = temp1;
                int temp2 = b[i+1];
                b[i+1] = b[i]; b[i] = temp2;
                notsorted = true;
            }
        }
    }
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