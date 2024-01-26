#include <iostream>
#include <vector>

using namespace std;

vector<vector<float>> submatrix(vector<vector<float>> arr, int n, int p, int q);
float determinant(vector<vector<float>> arr, int n);

int main()
{
    int n; cin >> n;
    vector<vector<float>> arr(n, vector<float>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cin >> arr[i][j];
    }

    cout << determinant(arr, n);

    return 0;
}

vector<vector<float>> submatrix(vector<vector<float>> arr, int n, int p, int q)
{
    vector<vector<float>> temp(n-1, vector<float>(n-1));
    int i_n, j_n;
    i_n = j_n = 0;

    for(int i=1; i<=n; i++)
    {
        if(i==p) continue;
        j_n=0;
        for(int j=1; j<=n; j++)
        {
            if(j==q) continue;
            temp[i_n][j_n] = arr[i-1][j-1];
            j_n++;
        }
        i_n++;
    }

    return temp;
}

float determinant(vector<vector<float>> arr, int n)
{
    float output=0;

    if(n==1)
    {
        output = arr[0][0];
    }
    else if(n==2)
    {
        output = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(i%2==0) output -= arr[0][i-1]*determinant(submatrix(arr, n, 1, i), n-1);
            else output += arr[0][i-1]*determinant(submatrix(arr, n, 1, i), n-1);
        }
    }

    return output;
}

