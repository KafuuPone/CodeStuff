#include <iostream>

using namespace std;

void solve() {
    int n; cin >> n;
    char** set = (char**)malloc((n-1)*sizeof(char*)); // create an array of strings
    char curr, next; cin >> curr;
    for(int i=0; i<n-1; i++) {
        cin >> next;
        char* str = (char*)malloc(2*sizeof(char));
        str[0] = curr; str[1] = next;
        set[i] = str;
        curr = next;
    }

    int count = 0;
    for(int i=0; i<n-1; i++)
        if(set[i][0] != '0') {
            count++;
            char a, b;
            a = set[i][0]; b = set[i][1];
            for(int j=i+1; j<n-1; j++)
                if(set[j][0]==a && set[j][1]==b)
                    set[j][0] = '0';
        }
    
    cout << count << endl;
}

int main() {
    int t; cin >> t;

    for(int i=0; i<t; i++)
        solve();

    return 0;
}