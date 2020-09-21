#include<iostream>
using namespace std;

int main(){
	int *i;
	
	// this prints some garbage address
	cout << i << endl;
	// the below will print some garbage value in the garbage address
	cout << *i << endl;

	int *j = 0;

	// this will print 0 i guess
	cout << j << endl;


	// this will compile but throws error at run time
	cout << *j << endl;
	return 0;
}


