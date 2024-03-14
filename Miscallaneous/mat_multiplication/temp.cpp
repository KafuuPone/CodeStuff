#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    int n; cin >> n; // number of random numbers
    int arr[n]; // array of n random numbers

    // assign random numbers into array
    for(int i=0; i<n; i++)
        arr[i] = rand()%100;

    // output array
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
    
    return 0;
}