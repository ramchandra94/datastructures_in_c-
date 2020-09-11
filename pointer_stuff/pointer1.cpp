#include<iostream>
using namespace std;

int main(){
	int a = 50;

	cout << a << endl;

	int *p = &a;

	cout << p << endl;

	int *q = p;

	(*q)++;

	cout << p << endl;

	cout << a << endl;

	return 0;

}
