#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        char ref[] = "codeforces";
        int count = 0;
        for(int j=0; j<10; j++) {
            char temp; cin >> temp;
            if(ref[j] != temp)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}