#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string word;
	vector<string> svec;

	while(cin >> word) {
		svec.push_back(word);
		for (auto i : svec)
			cout << i << " ";
	}
	return 0;
}