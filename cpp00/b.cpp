#include <iostream>
#include <string>

using namespace std;

int main()
{
	string myString;
	getline(cin, myString);

	string mydelimString;
	getline(cin, mydelimString, ' ');


	cout << myString << endl;
	cout << mydelimString << endl;
	return 0;
}
