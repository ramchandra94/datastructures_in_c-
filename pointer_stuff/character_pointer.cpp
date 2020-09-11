#include<iostream>
using namespace std;

int main(){
	char str[] = "ram";
	char *ptr = str;

	cout << ptr << endl;

	cout << 0[str] << endl;

	cout << 1[str] << endl;

	cout << 2[str] << endl;
	return 0;
}
