//Write a program to implement Bubble sort.
#include <iostream>
using namespace std;
int main()
{
	cout<<"Welcome to the program for bubble sorting\n";
	cout<<"Please enter the number of elements in your list.\n";
	int temp_n;
	cin>>temp_n;
	cout<<"Please enter an array of your unsorted numbers.\n";
	int arr[temp_n];
	int counte=0;
	for(int i =0;i<temp_n;i++)
	{
		cin>>arr[i];
	}
	for(int i =temp_n;i>-1;i--)
	{
			int count =0;
		for(int j=temp_n-1;j>0;j--)
		{
			if(arr[i]>arr[j])
			{
				arr[i] += arr[j];
				arr[j] = arr[i] - arr[j];
				arr[i] = arr[i] - arr[j];
				count++;
			}
		}
		counte++;
		if(count<0)
		{
			break;
		}
		}

	
	for(int i =0;i<temp_n;i++)
	{
		cout<<arr[i];
		cout<<"\n";
		
	}
	}
