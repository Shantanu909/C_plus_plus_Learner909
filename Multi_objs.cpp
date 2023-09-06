//Creata a class person and create diff objects of class person

#include <iostream>
using namespace std;

class Person
{	
	public:
	bool classified = true;
	void Doctor(){
		cout<<"\nGet me my Stethoscope, Stat.\n";
	}
	void Employee(){
		cout<<"How far are we on those data sheets?\n";
	}
	void Student(){
		cout<<"Can I borrow this pen?\n";
	}		
};
int main()
{
	Person info_status;
	cout<<info_status.classified;
	Person dr;
	dr.Doctor();
	Person Emp;
	Emp.Employee();
	Person Stud;
	Stud.Student();
	
	
}