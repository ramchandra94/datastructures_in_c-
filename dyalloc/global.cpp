#include<iostream>
using namespace std;

#define multiply(a, b) a*b

int g_var;
float f_var;
char c_var;
bool b_var;
int main(){

	int g_var = 4;
	
	cout << multiply(2+3, 3+5) << endl;

	cout << g_var << endl;

	cout << f_var << endl;

	cout << c_var << endl;

	cout << b_var << endl;

	int x = 36/6*6;

	cout << x << endl;

	return 0;
}
