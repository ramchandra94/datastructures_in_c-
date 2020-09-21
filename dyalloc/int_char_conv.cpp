#include<iostream>
using namespace std;

void updateChar(int *p){
	*p = 610 % 255;
}

int main(){
	char c = 'A';
	
	updateChar((int *)&c);

	cout << c << endl;

	return 0;
}
