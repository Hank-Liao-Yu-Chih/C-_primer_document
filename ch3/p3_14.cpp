#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int val;
	vector<int> ivec;

	while(cin >> val) {
		ivec.push_back(val);
		for (auto i : ivec)
			cout << i << " ";
	}
	return 0;
}