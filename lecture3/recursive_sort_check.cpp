#include<iostream>
using namespace std;

bool is_sorted(int arr[], int size){
	if(size == 1){
		return true;
	}

	if(arr[0] > arr[1]){
		return false;
	}

	return is_sorted(arr + 1, size - 1);
}

int main(){
	int arr[] = {1, 2, 3, 7, 5, 6};

	cout << is_sorted(arr, 6) << endl;

	return 0;
}

