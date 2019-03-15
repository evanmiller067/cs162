#include "student.h"

int main()
{
	Student s1("G10", 3.9);
	Student s2("G20", 3.5);

	s1.print();
	s2.print();

	//write code to test Student::isLessThanByID

	cout << " Less than By ID function: " << s1.isLessThanByID(s2) << endl;
	
	//Write code to test Student::qualifyForHonor

	cout << " Student One qualified for Honor: " << s1.qualifyForHonor(3.5) << endl;

	cout << " Student Two qualified for Honor: " << s2.qualifyForHonor(4.0) << endl;

	return 0;


/*	if(s1.isLessThanByID(s2))
	{
		cout << " True, it worked. " << endl;
	}
	else
	{
		cout << " False, did NOT work.  " << endl;
	}
	//write code to test Student::qualifyForHonor
	
	if(s1.qualifyForHonor(3.25))
	{
		cout << "Student One  qualified for Honors!" << endl;
	}
	else
	{
		cout << " Student One did NOT qualify. " << endl;
	}
	if(s2.qualifyForHonor(3.25))
	{
		cout << " Student Two Qualifed! " << endl;
	}
	else
	{
		cout << "Student Two did NOT qualify." << endl;
	}
	return 0; */
}
