#include <iostream>

using namespace std;

void solve() {
    int n; cin >> n;
    bool matrix[7][7];
    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++)
            matrix[i][j] = false;
    
    // input and calc
    int count = 0;
    char curr, next;
    cin >> curr;
    for(int i=0; i<n-1; i++) {
        cin >> next;
        if(matrix[curr-'a'][next-'a'] == false) {
            matrix[curr-'a'][next-'a'] = true;
            count++;
        }
        curr = next;
    }

    cout << count << endl;
}

int main() {
    int t; cin >> t;

    for(int i=0; i<t; i++)
        solve();

    return 0;
}