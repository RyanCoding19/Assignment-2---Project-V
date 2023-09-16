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
};




int main()
{
	string line;
	int counter = 0;
	ifstream myfile;
	STUDENT_DATA names[STUDENT_NUMBER];
	myfile.open("StudentData.txt");

	vector<string> FirstData;
	vector<string> LastData;
	vector<string> email;

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
	return 0;
}