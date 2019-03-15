/*This program demos the strstr function
Locate substring  strstr(str1, str2);
Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
str1
C string to be scanned.
str2
C string containing the sequence of characters to match.
*/


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char title[101];
	char srchTitle[101];
	//set title to be The Lion King
	strcpy(title, "The Lion King");
	//ask the user what they want to search for
	cout << "Please enter search title:";
	cin.get(srchTitle, 101);
	if (strstr(title, srchTitle) != NULL)
	{
		cout << "Title found!" << endl;
		cout << title << endl;
	}
	else
	{
		cout << "Title not found!" << endl;
	}

	return 0;
}
