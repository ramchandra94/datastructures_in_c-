#include<iostream>
using namespace std;

int factorial(unsigned int n) {
	int prev_fact = factorial(n-1);
	return n * prev_fact;
}

int main(){
	int n;
	cin >> n;

	int fact = factorial(n);
	cout << fact << endl;
	return 0;
}
