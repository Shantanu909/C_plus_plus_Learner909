#include <iostream>

int main() {
	int sum=0,size=10,temp=0;
    std::cout << "Welcome to the code for Max value.\n";
    std::cout << "How many numbers do you want to compare.\n";
    
	std::cin >> size;
    int arr[10] ;
    
    std::cout << "Please enter the numbers one by one with an enter key after each entry\n";
    for(int i =0;i<size;i++)
    {
    	std::cin >> arr[i];
    	if(temp<arr[i])
    	{
    		temp = arr[i];
		}
		}
		
	 std::cout << "The max of the given numbers = ";
	  std::cout << temp;
		}
	

