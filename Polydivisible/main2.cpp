#include <bits/stdc++.h>

using namespace std;

// Function to convert from decimal to base-n, return string length
void conv(long long num, int base, int a[]) {
    int n = log(num)/log(base);
    for(int i=n; i>=0; i--) {
        a[i] = num%base;
        num /= base;
    }
}

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

int main() {
    // int num10 = 123456789, base = 14;
    // int len = log(num10)/log(base) + 1;
    // int num[len];
    // conv(num10, base, num);
    // display(num, len);

    // Setting up
    int limit = 11; // max digit length
    int base = 11; // base checking
    long long limit_b = 1;
    for(int i=0; i<limit; i++)
        limit_b *= base;
    limit--;

    // Start process
    long long count[limit] = {0}; // num of digits - 1 = index = log(num)/log(base)
    for(long long i=1; i<= limit_b; i++) {
        int len_m_1 = log(i)/log(base);
        int temp[len_m_1+1];
        conv(i, base, temp);
        if(polydiv_num(temp, len_m_1+1))
            count[len_m_1]++;
    }

    // Display
    for (int i = 0; i < limit; i++) {
        cout << count[i] << " ";
    }
    cout << endl;

    return 0;
}