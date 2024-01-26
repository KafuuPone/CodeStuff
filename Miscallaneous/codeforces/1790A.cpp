#include <iostream>

using namespace std;

void solve() {
    string pi = "314159265358979323846264338327";
    string input; cin >> input;
    int i;
    for(i=0; i<input.length(); i++)
        if(pi[i] != input[i]) break;
    cout << i << endl;
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}