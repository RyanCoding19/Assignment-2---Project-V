#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define STUDENT_NUMBER 28
using namespace std;



struct STUDENT_DATA
{
	string firstName;
	string lastName;
	string email;
};




int main()
{
	string line;
	int counter = 0;
	int counter2 = 0;
	ifstream myfile;
	STUDENT_DATA names[STUDENT_NUMBER];

	vector<string> FirstData;
	vector<string> LastData;
	vector<string> email;

#ifdef _DEBUG
	myfile.open("StudentData.txt");
	cout << "application running standard" << endl;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			size_t pos = line.find_first_of(',');
			names[counter].lastName = line.substr(0, pos);
			names[counter].firstName = line.substr(pos + 1);
			counter++;
		}
		myfile.close();

		for (int i = 0; i < STUDENT_NUMBER; i++)
		{
			FirstData.push_back(names[i].firstName);
			LastData.push_back(names[i].lastName);
		}
		

	}
	else cout << "Can't read file";




	for (int i = 0; i < STUDENT_NUMBER; i++)
	{
		cout << "Student #" << i+1 << endl;
		cout << "First Name:" << FirstData[i] << endl;
		cout << "Last Name: " << LastData[i] << endl;
	}


#else
	myfile.open("StudentData_Emails.txt");
	cout << "application running pre-release" << endl;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			size_t pos = line.find_first_of(',');
			size_t pos2 = line.find_last_of(',');
			names[counter2].lastName = line.substr(0, pos);
			names[counter2].firstName = line.substr(pos+1, pos2-pos-1);
			names[counter2].email = line.substr(pos2 + 1);
			counter2++;
		}
		myfile.close();

		for (int i = 0; i < STUDENT_NUMBER; i++)
		{
			FirstData.push_back(names[i].firstName);
			LastData.push_back(names[i].lastName);
			email.push_back(names[i].email);
		}


	}
	else cout << "Can't read file";




	for (int i = 0; i < STUDENT_NUMBER; i++)
	{
		cout << "Student #" << i + 1 << endl;
		cout << "First Name:" << FirstData[i] << endl;
		cout << "Last Name: " << LastData[i] << endl;
		cout << "email: " << email[i] << endl;
	}
#endif




	return 0;
}