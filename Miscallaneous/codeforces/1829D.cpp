#include <iostream>

using namespace std;

void solve() {
    int n, num; cin >> n >> num;
    bool output = false;
    int a = 0;
    while(n%3 == 0) {
        n /= 3;
        a++;
    }
    if(num%n != 0)
        cout << "NO" << endl;
    else {
        num /= n;
        int num_2, num_3;
        num_2 = num_3 = 0;
        while(num%2 == 0) {
            num /= 2;
            num_2++;
        }
        while(num%3 == 0) {
            num /= 3;
            num_3++;
        }
        if(num != 1 || num_2+num_3 > a)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++)
        solve();
    return 0;
}