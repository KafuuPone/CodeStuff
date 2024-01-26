#include <iostream>

using namespace std;

void solve() {
    int n, s, r; cin >> n >> s >> r;
    int temp = r/(n-1), n1 = r-temp*(n-1);
    for(int i=0; i<n1; i++) cout << temp+1 << ' ';
    for(int i=0; i<n-1-n1; i++) cout << temp << ' ';
    cout << s-r << endl;
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}