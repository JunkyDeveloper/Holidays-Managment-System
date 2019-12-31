//holiday management
//1 abhishek sharma 04 04 2001 1 mansi sharma 08 01 2001 1 manisha jangir 13 07 2001
#include<iostream>
#include<vector>
using namespace std;

class Date{
	public:
		int day;
		int month;
		int year;

	void printDate(){
		cout<<day<<"/"<<month<<"/"<<year<<"\n";
	}
	Date(){
		day = 1;
		month = 1;
		year = 2000;
	}
	Date(int a , int b, int c){
		day = a;
		month = b;
		year = c;		
	}
};

class Employee{
	private:
		string firstName;
		string surName;
		Date dateOfBirth;
		vector<Date> holiDays;
		int countHolidays;
		int oldAge;
	
	public:
		Employee(string s1 , string s2 , Date dob){
			surName = s2;
			dateOfBirth = dob;		
			firstName = s1;
			if(dob.year < 1970)
				oldAge = 1;
			else
				oldAge = 0;
			
			countHolidays = 0;
			cout<<"Employee called\n";
		}
		Employee(){
			firstName = "";
			surName = "";
			Date dob(0 , 0 ,0);		
			dateOfBirth = dob;
		}
		void printEmployee(){
			cout<<"|||Employee Name : ";
			cout<<firstName<<" "<<surName<<"\n";
			cout<<"|||Dob :";
			dateOfBirth.printDate(); 
			cout<<"Total Leave Taken : "<<countHolidays;
			cout<<"\n";			
		}
		void printAllLeaveDates(){
			cout<<"||| Dates on which Employee Taken the Leave\n";
			vector<Date> :: iterator it;
			for(it = holiDays.begin() ; it !=  holiDays.end() ; it++){
				(*it).printDate();
			}
		}
		void setEmp(string s1 , string s2 , Date dob){
			firstName = s1;
			surName = s2;
			dateOfBirth = dob;				
			if(dob.year < 1970)
				oldAge = 1;
			else
				oldAge = 0;

			cout<<"Employee Edited\n";	
		}
		string getFirstName(){
			return firstName;
		}
		
		string getLastName(){
			return surName;	
		}
		
		int giveLeave(Date leaveDate){
			int totalPossible;
			if(oldAge == 0)
				totalPossible = 30;
			else
				totalPossible = 32;

			if(countHolidays < totalPossible){
				holiDays.push_back(leaveDate);
				countHolidays++;
				cout<<"|||\n";
				cout<<"Leave Grantedd!!!\n";
				return 1;
			}	
			else{
				cout<<"### MESSAGE ###\n";
				cout<<"You already Crossed the limit of maximam holidays\n";
				return 0;
			}	
		}
};

//creating employyee
void createEmployee(vector<Employee> &Emp)
{	
	string s1 , s2;
	int a , b, c;
	cout<<"Enter Employee First Name :  ";
	cin>>s1;
	cout<<"Enter Employee SurName :  ";
	cin>>s2;
	cout<<"Enter Date Of Birth(format : 08 01 2001):  ";
	cin>>a;
	cin>>b;
	cin>>c;
	Date dob(a ,b ,c);
	
	Employee e1(s1,s2,dob);	
	Emp.push_back(e1);	
	
	cout<<"Employee Created!!!!\n\n";
}
//display all employee
void displayAllEmployee(vector<Employee> &Emp){
	int count =  Emp.size();
	if(count == 0)
		cout<<"No Employee available!!!!!!\n";
		
	else{
		for(int i = 0 ; i < count ; i++){
			cout<<"|||"<<i+1<<".\n";
			Emp[i].printEmployee();
			cout<<"\n\n";
		}
	}
}

//delete employee
void deleteEmployee(vector<Employee> &Emp){
	int count = Emp.size();	
	if(count == 0){
		cout<<"There is no Employee to Delete\n";
		return;	
	}

	string s1,s2;
	cout<<"Enter the first name of employee : ";
	cin>>s1;
	cout<<"Enter the last name of employee : ";
	cin>>s2;

	vector<Employee> :: iterator target = Emp.begin();
	vector<Employee> :: iterator it;	
	for(it = Emp.begin() ; it != Emp.end() ; it++){
		if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
			target = it;
			break;
		}
	}	
	if(target == Emp.begin()){
		cout<<"Employee NOT FOUND !!!!!\n";
	}
	else{
		Emp.erase(target);
		cout<<"Employee Deleted!!!\n";
	}
}

// display one employee with dates of leave
void displayOneEmployee(vector<Employee> &Emp){
	string s1 , s2;
	cout<<"Enter the details of that Employee\n";
	cout<<"First Name : ";
	cin>>s1;
	cout<<"Last Name : ";
	cin>>s2;

	vector<Employee> :: iterator it;	
	for(it = Emp.begin() ; it != Emp.end() ; it++){
		if((*it).getFirstName() == s1 && (*it).getLastName() == s2){	
			cout<<"|||#\n";
			(*it).printEmployee();
			(*it).printAllLeaveDates();
			break;
		}
	}
	if(it==Emp.end())
		cout<<"Employee not Found....\n";
}

//Give a Leave
void giveALeave(vector <Employee> &Emp){
	string s1 , s2;
	cout<<"##Enter the Details of Employee\n";
	cout<<"First Name : ";
	cin>>s1;
	cout<<"Last Name : ";
	cin>>s2;
	cout<<"Enter the date Emoloyee Want Leave For(format : 01 01 2000) : ";
	int a,b,c;
	cin>>a>>b>>c;
	Date leaveDate (a,b,c);

	vector<Employee> :: iterator it;
	for(it = Emp.begin() ; it !=  Emp.end(); it++){
		if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
			(*it).giveLeave(leaveDate);
			break;
		}
	}
}

//main 
int main(){
	int choice = 1;
	vector<Employee> Emp;
	while(choice != 0){
		cout<<"0 . EXIT\n";
		cout<<"1 . Create Employee\n";
		cout<<"2 . Delete Employee\n";
		cout<<"3 . Display All Employee\n";
		cout<<"4 . Show Specific Employee\n";
		cout<<"5 . Give a Leave\n";
		cin>>choice;
		
		if(choice == 1)
			createEmployee(Emp);
		else if(choice == 2)
			deleteEmployee(Emp);
		else if(choice == 3)
			displayAllEmployee(Emp);
		else if(choice == 4)
			displayOneEmployee(Emp);
		else if(choice ==5)
			giveALeave(Emp);			
		else
			cout<<"Incorrct Choice!!!!\n";		
					
	}

	
}
