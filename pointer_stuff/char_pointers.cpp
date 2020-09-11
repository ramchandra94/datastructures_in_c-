#include<iostream>
using namespace std;

int main(){

	int a[] = {1, 2, 3};

	char b[] = "abc";
	
	cout << a << endl;

	cout << b << endl;

	char *p = &b[0];

	cout << p << endl;

	char c = 'a';
	char *pc = &c;
	cout << c << endl;

	cout << pc << endl;
	return 0;
}
