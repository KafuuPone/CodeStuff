#include <bits/stdc++.h>

using namespace std;

// Function to display the array
void display(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Function to determine whether a single array is a polydivisible number
bool polydiv_num(int a[], int n) {
    long long num = a[0];
    for(int i=1; i<=n; i++) {
        if(num%i != 0)
            return false;
        num *= n+1;
        num += a[i];
    }
    return true;
}

// Function to find the permutations
void polydiv_all(int a[], int n)
{
    int count = 0, progress = 0;
    do {
        if(polydiv_num(a, n)) {
            display(a, n);
            count++;
        }
        if(a[0] != progress) {
            progress = a[0];
            cout << progress << '/' << n << endl;
        }
    } while (next_permutation(a, a + n));
    if(count == 0)
        cout << "Nothing found." << endl;
}

int main() {
    for (int base = 15; base <= 20; base++) {
        cout << "Base:" << base << endl;
        int n = base - 1;
        int num[n];
        for(int i=0; i<n; i++)
            num[i] = i+1;
        polydiv_all(num, n);
        cout << "---" << endl;
    }

    return 0;
}