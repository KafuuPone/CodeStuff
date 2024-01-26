#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>

using namespace std;

void solve(int n);
vector<vector<float>> submatrix(vector<vector<float>> arr, int n, int p, int q);
float determinant(vector<vector<float>> arr, int n);
vector<vector<float>> replaced_matrix(vector<vector<float>> ori_mat, vector<float> const_mat, int n, int a);

int main()
{
    cout << "Input number of variables: ";
    int n; cin >> n;

    if(n<=10 && n>0) solve(n);
    else cout << endl << "Your input number is not valid or too large to compute." << endl;

    return 0;
}

void solve(int n)
{
    cout << endl;

    //Declare 2 matrices
    vector<vector<float>> arr(n, vector<float>(n));
    vector<float> arr_const(n);

    //Input section
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << char('`'+i) << j << " = ";
            cin >> arr[i-1][j-1];
        }
        cout << char('`'+i) << n+1 << " = ";
        cin >> arr_const[i-1];
        cout << endl;
    }

    //Real solving
    float det=determinant(arr, n);
    if(det!=0)
    {
        for(int i=1; i<=n; i++) cout << 'x' << i << " = " << determinant(replaced_matrix(arr, arr_const, n, i), n)/det << endl;
    }
    else cout << "There are either no solutions or infinite solutions for the equations." << endl;
}

//Submatrix of a matrix for an element
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

//Determinant of a matrix
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

//Matrix with a column replaced
vector<vector<float>> replaced_matrix(vector<vector<float>> ori_mat, vector<float> const_mat, int n, int a)
{
    vector<vector<float>> temp;
    temp = ori_mat;
    for(int i=0; i<n; i++) temp[i][a-1] = const_mat[i];
    return temp;
}
