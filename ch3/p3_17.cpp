#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

	vector<char> cvector = {'a', 'b', 'c', 'd', 'e', 'f'};

	cout << "orginal Char Vector" << endl;
	for (auto i : cvector)
		cout << i << " ";
	cout << endl;

	cout << "Modify Char Vector...." << endl;
	for (auto &i : cvector)
		i = toupper(i);

	cout << "after Modify Char Vector" << endl;
	for (auto i : cvector)
		cout << i << " ";
	cout << endl;


	return 0;
}