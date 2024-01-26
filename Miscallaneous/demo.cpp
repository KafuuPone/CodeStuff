#include <iostream>
#include <vector>

using namespace std;

float average(vector<float> arr, int n)
{
    float temp=0;
    for(int i=0; i<n; i++) temp+=arr[i];
    return temp/n;
}

int main()
{
    cout << "Input number of datas: ";
    int n; cin >> n;
    cout << "Input data: ";
    vector<float> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << average(arr, n);
}
