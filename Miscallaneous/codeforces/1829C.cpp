#include <iostream>

using namespace std;

void solve() {
    int n; cin >> n;
    int count1, count2;
    count1 = count2 = 0;
    int min01, min10, min11;
    min01 = min10 = min11 = 4e5+1;
    for(int i=0; i<n; i++) {
        int time, skill;
        cin >> time >> skill;
        if(skill == 01) {
            count2++;
            if(time < min01)
                min01 = time;
        }
        else if(skill == 10) {
            count1++;
            if(time < min10)
                min10 = time;
        }
        else if(skill == 11) {
            count1++; count2++;
            if(time < min11)
                min11 = time;
        }
    }
    if(count1==0 || count2==0)
        cout << -1 << endl;
    else {
        if(min11 < min01+min10)
            cout << min11 << endl;
        else
            cout << min01+min10 << endl;
    }
}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++)
        solve();
    return 0;
}