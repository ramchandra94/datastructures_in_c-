#include<iostream>
using namespace std;

int main(){
	
	int a = 54;
	char c = 'a';

	float b = 34.7568;

	void *i = &a;
	char *cp = &c;
	float *fp = &b;

	cout << (void *)cp << endl;

	cout << i << endl;
	
	
	return 0;
}
