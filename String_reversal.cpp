#include <iostream>
using namespace std;
void revarr(int arr[], int size) {
    if (size <= 1) {
        return; 
    }
    int *left = arr;
    int *right = arr + size - 1; 
    while (left < right) {
        swap(*left, *right);
        left++;
        right--;
    }
}

int main() {
    int size;
	cin>>size;
	int arr[size];
	for (int i = 0; i < size; i++) {
        cin >> arr[i]; 
    }
	size = sizeof(arr) / sizeof(arr[0]);
    revarr(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i]; 
		cout << " ";
    }
}
