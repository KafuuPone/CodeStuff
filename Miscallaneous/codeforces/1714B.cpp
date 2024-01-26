#include <iostream>

using namespace std;

void solve()
{
    int n; cin >> n;
    int numlist[n]; for(int i=0; i<n; i++) cin >> numlist[i];

    bool repeat=true;
    int num_nondist=0;
    for(int i=n-2; i>=0&&repeat; i--)
    {
        for(int j=n-1; j>i&&repeat; j--)
        {
            if(numlist[i]==numlist[j])
            {
                num_nondist=i+1;
                repeat=false;
            }
        }
    }
    cout << num_nondist << endl;
}

int main()
{
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();

    return 0;
}
