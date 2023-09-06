/*Swapping two numbers using pointers*/
#include <iostream>
using namespace std;
int main()
{
	int temp_1=5;
	int temp_2=6;
	int *p1;
	int **p2;
	
	//With a single pointer
	/**
	*p1 = temp_1;
	temp_1 = temp_2;
	temp_2 = *p1;	
	cout << temp_1;
	cout << "\n";
	cout << temp_2;
	*/
	//With double pointers
	p1 = &temp_1;
	temp_1 = temp_2;
	p2 = &p1;
	temp_2 = *p1;	
	cout << temp_1;
	cout << "\n";
	cout << temp_2;
}