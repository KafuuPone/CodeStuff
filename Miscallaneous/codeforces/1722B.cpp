#include <iostream>

using namespace std;

string solve()
{
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    for(int i=0; i<n; i++)
    {
        if(s1[i]=='G') s1[i]='B';
        if(s2[i]=='G') s2[i]='B';
    }

    int count=0;
    for(int i=0; i<n; i++) count += s1[i]!=s2[i];
    if(count==0) return "YES";
    else return "NO";
}

int main()
{
    int t; cin >> t;
    for(int i=0; i<t; i++) cout << solve() << endl;
    return 0;
}
