#include <iostream>

using namespace std;

string solve()
{
    int n; cin >> n;
    string s; cin >> s;
    if(n==5)
    {
        string model = "Timur";
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(model[i]==s[j])
                {
                    count++;
                    break;
                }
            }
        }
        if(count==5) return "YES";
        else return "NO";
    } else return "NO";
}

int main()
{
    int t; cin >> t;
    for(int i=0; i<t; i++) cout << solve() << endl;

    return 0;
}
