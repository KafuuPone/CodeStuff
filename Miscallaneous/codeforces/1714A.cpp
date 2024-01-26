#include <iostream>

using namespace std;

int timediff_min(int H_final, int M_final, int H_initial, int M_initial)
{
    int T_final, T_initial, T_diff;

    T_final = H_final*60+M_final;
    T_initial = H_initial*60+M_initial;

    T_diff = T_final-T_initial;
    if(T_diff<0) T_diff += 24*60;

    return T_diff;
}

void solve()
{
    int n, H, M; cin >> n >> H >> M;
    int T_min=24*60;
    for(int i=0; i<n; i++)
    {
        int H_final, M_final, timediff; cin >> H_final >> M_final;
        timediff = timediff_min(H_final, M_final, H, M);
        if(timediff<T_min) T_min=timediff;
    }
    cout << T_min/60 << ' ' << T_min%60 << endl;
}

int main()
{
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();

    return 0;
}
