#include <iostream>
#define N 20 // number of approximations

using namespace std;

class frac {
    public:
        int num; // numerator
        int den; // denominator
};

// calculates a+1/b in fractions
frac temp_func(int a, frac b) {
    frac output;
    output.num = a*b.num+b.den;
    output.den = b.num;
    return output;
}

// calculates nearest approx using first n numbers in array
frac approx(const int arr[N], int n) {
    frac output = {arr[n-1], 1};
    for(int i=n-2; i>=0; i--)
        output = temp_func(arr[i], output);
    return output;
}

int main() {
    long double num; cin >> num;
    int arr[N] = {0};
    for(int i=1; i<=N; i++) {
        int temp = (int)num;
        if(i>1 && temp == 0)
            break;
        arr[i-1] = temp;
        num -= temp;
        num = 1/num;
    }

    for(int i=0; i<N; i++)
        cout << arr[i] << ' ';
    cout << endl;
    for(int i=1; i<=N; i++) {
        frac num_approx = approx(arr, i);
        cout << num_approx.num << '/' << num_approx.den << ' ';
    }

    return 0;
}