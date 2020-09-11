#include<iostream>
using namespace std;

int main(){
	int a = 50;

	int *p = &a;

	cout << (*p)++ << " ";

	cout << a << endl;

	return 0;
}
