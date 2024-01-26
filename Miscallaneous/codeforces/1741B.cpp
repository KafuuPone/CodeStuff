#include <iostream>

using namespace std;

void solve();

int main()
{
    int t; cin >> t;
    for(int i=0; i<t; i++)
        solve();
    return 0;
}

void solve()
{
    int n; cin >> n;
    if(n<2 || n==3)
        cout << "-1";
    else if(n%2==0)
    {
        for(int i=n; i>0; i--)
            cout << i << ' ';
    }
    else
    {
        cout << n-1 << ' ' << n << ' ';
        for(int i=2; i<n; i++)
            cout << i-1 << ' ';
    }
    cout << endl;
}
