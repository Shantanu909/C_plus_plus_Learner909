#include <iostream>
using namespace std;
int main()
{
	cout<<"Welcoem to the program for bubble sorting\n";
	cout<<"Please enter the number of elemnets in your list.";
	int temp_n;
	cin>>temp_n;
	cout<<"Please enter an array of your unsorted numbers.";
	int arr[temp_n];
	for(int i =0;i<temp_n;i++)
	{
		cin>>arr[i];
	}
	for(int j =0;j<temp_n;j++)
	{
		if(j<temp_n-1)
		{
		    if(arr[j]>arr[j+1])
			{
				int u = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = u;
			}
		}
		else if(j==temp_n-1)
		{
		
			if(arr[j]>arr[0])
			{
				int u = arr[0];
				arr[0] = arr[j];
				arr[j] = u;
			}
		}
	for(int i =0;i<temp_n;i++)
	{
		cout<<arr[i];
		cout<<"\n";
	}
	}
	}
