#include <iostream>

using namespace std;

bool compare3(string s1, string s2)
{
    int count=0;

    for(int i=0; i<3; i++)
        count += s1[i]!=s2[i];

    if(count==0)
        return true;
    else
        return false;
}

void solve()
{
    int n; cin >> n;
    string words[3][n];
    for(int p=0; p<3; p++)
    {
        for(int i=0; i<n; i++)
            cin >> words[p][i];
    }

    int score[3] = {n, n, n};

    for(int p=0; p<3; p++) //Select player
    {
        for(int i=0; i<n; i++) //Select words of said player to compare
        {
            int simcount=0;
            for(int pcomp=0; pcomp<3; pcomp++) //Other 2 players to compare
            {
                if(pcomp!=p)
                {
                    for(int j=0; j<n; j++) //Index of other 2 players
                    {
                        if(compare3(words[p][i], words[pcomp][j]))
                        {
                            simcount++; break;
                        }
                    }
                }
            }
            if(simcount==0) score[p]+=2;
            else if(simcount==2) score[p]-=1;
        }
    }

    for(int i=0; i<3; i++) cout << score[i] << ' ';
    cout << endl;
}

int main()
{
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();

    return 0;
}
