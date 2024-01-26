#include <iostream>
#include <string>

using namespace std;

// mode "db": dec to bin, mode "bd": bin to dec
string convert_db(int num, int dim) {
    string output = "";
    for(int i=0; i<dim; i++) {
        if(num%2 == 0)
            output.insert(0, "0");
        else
            output.insert(0, "1");
        num /= 2;
    }
    return output;
}

int convert_bd(string num, int dim) {
    int output = 0, exp2 = 1;
    for(int i=dim-1; i>=0; i--) {
        output += ((char)num[i] - '0')*exp2;
        exp2 *= 2;
    }
    return output;
}

int main() {
    // number of variables
    int dim; cout << "Dim: "; cin >> dim;
    // num = 2^n
    int num = 1;
    for(int i=0; i<dim; i++)
        num *= 2;
    // create minterm map
    int* kmap = (int*)malloc(2*num*sizeof(int)); // row 0: value, 0 or 1; row 1: number of circles within(initial, value1 - 0, value0 - -1)
    for(int i=0; i<num; i++) {
        kmap[0*num + i] = 0;
        kmap[1*num + i] = -1;
    }
    // input minterm values
    cout << "minterm values (input -1 when done):";
    int input;
    while(true) {
        cin >> input;
        if(input == -1)
            break;
        if(input < num && input >= 0) {
            kmap[0*num + input] = 1;
            kmap[1*num + input] = 0;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }

    // // test output
    // for(int i=0; i<2; i++) {
    //     for(int j=0; j<num; j++)
    //         cout << kmap[i*num+j] << " ";
    //     cout << endl;
    // }
    return 0;
}