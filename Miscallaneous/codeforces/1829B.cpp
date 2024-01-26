#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        int n; cin >> n;
        int max_len, len;
        max_len = len = 0;
        for(int i=0; i<n; i++) {
            int temp; cin >> temp;
            if(temp == 0)
                len++;
            else {
                if(len > max_len)
                    max_len = len;
                len = 0;
            }
        }
        if(len > max_len)
            max_len = len;
        cout << max_len << endl;
    }
    return 0;
}