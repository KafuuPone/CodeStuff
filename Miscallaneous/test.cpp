#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n; cin >> n;
	int num = 1; for(int i = 0; i < n; i++) num*=2;
	long double a[num];
	for(int i = 0; i < num; i++) a[i] = log(i+2);
	//Input complete
	
	for(int x = n-1; x >= 0; x--) {
		for(int i = 0; i < pow(2, x); i++) {
			
		}
	}
}