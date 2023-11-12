#include <iostream>

int main() {
	int sum=0,size=10;
    std::cout << "Welcome to the code for addition.\n";
    std::cout << "How many numbers do you want to add.\n";
    
	std::cin >> size;
    int arr[10] ;
    
    std::cout << "Please enter the numbers one by one with an enter key after each entry\n";
    for(int i =0;i<size;i++)
    {
    	std::cin >> arr[i];
    	
    	
    		
    			sum = sum+arr[i];
			
		}
		
	 std::cout << "The sum of your given numbers = ";
	  std::cout << sum;
		}
	

