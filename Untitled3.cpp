#include <iostream>
using namespace std;
int max(int x,int arr[])
{
	int max;
	int temp_arr[x];
	for(int i =0;i<x;i++)
	{
		temp_arr[i] = arr[i];
	}
		for(int i =0;i<x;i++)
	{
		for(int j=1;j<x-1;j++)
		{
				if(temp_arr[i]>temp[j])
				{
					max = temp_arr;
				}

		}
	}
	int count = 0;
	
	while (max>0)
	{
		max = max/10;
		count++;
	}
	
	//for(int i =10;i<temp_arr;i+d)
	//{
	//	if(max%i!=0)
	//{
		//	count++;
		//}
//	}
return count;
}

	

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
	int c;
	c = max(temp_n,arr[]);
	for(int i =0;i<c;i++)
	{
		for(int j =0;i<c-1;c++)
	}
}
