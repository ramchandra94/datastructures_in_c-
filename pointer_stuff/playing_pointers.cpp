#include<iostream>
using namespace std;

int main(){

	int a = 5;

	char ch = 'a';

	char * p = &ch;

	cout << "directly printing character " << ch << endl;

	cout << "printing character through pointer " << *p << endl;

	cout << "printing the pointer itself " << p << endl;

	cout << "printing the 0th index of pointer " << p[0] << endl;

	ch++;

	cout << "printing the dereference of pointer after incrementing the character " << *p << endl;


	return 0;
}
