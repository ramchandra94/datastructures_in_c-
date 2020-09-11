#include<iostream>
using namespace std;

int main(){
	
	int a[6] = {1, 2, 3};

	int * b = a;

	cout << a << endl;

	cout << b << endl;

	cout << a[2] << endl;

	cout << b[2] << endl;



	return 0;
}
