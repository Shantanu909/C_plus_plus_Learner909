#include <iostream>

int main() {
	int sum=0,size=10,n,nx,temp1,temp2;
    std::cout << "Welcome to the code for operators.\n";
    
    std::cout << "1. Arithmetic\n";
    std::cout << "2. Logical\n";
    std::cout << "3. Relational\n";
    std::cout << "4. Bit-wise\n";
    std::cout << "5. Tertiary\n";
    std::cout << "Please enter the choice of operation.\n";
    std::cin >>n;
    switch(n){
	
	case 1:
	std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Remainder\n";
    std::cout << "Please enter the choice of operation.\n";
    	std::cin >> nx;
		switch(nx)
		{
			case 1:
				std::cout << "Please enter frist number\n";
				std::cin >> temp1;
    			std::cout << "Please enter second number\n";	
    			std::cin >> temp2;
    			std::cout << "The sum = ";
    			std::cout << temp1+temp2;
			break;
		}
	break;
	}std::cin >> size;
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
	

