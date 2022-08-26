#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// (a) 合法 0個
	vector<int> v1;
	cout << "v1:" << endl;
	for (auto i : v1)
		cout << i << " ";
	cout << endl;

	// (b) 合法 10個 都是0
	vector<int> v2(10);
	cout << "v2:" << endl;
	for (auto i : v2)
		cout << i << " ";
	cout << endl;

	// (c) 合法 10個 都是42
	vector<int> v3(10, 42);
	cout << "v3:" << endl;
	for (auto i : v3)
		cout << i << " ";
	cout << endl;

	// (d) 合法 1個 是42
	vector<int> v4{42};
	cout << "v4:" << endl;
	for (auto i : v4)
		cout << i << " ";
	cout << endl;

	// (e) 合法 2個 是42, 10
	vector<int> v5{42, 10};
	cout << "v5:" << endl;
	for (auto i : v5)
		cout << i << " ";
	cout << endl;

	// (f)合法 10個 是空字串
	vector<string> v6{10};
	cout << "v6:" << endl;
	for (auto i : v6)
		cout << i << " ";
	cout << endl;

	// (h)合法 10個 是"hi"
	vector<string> v7{10, "hi"};
	cout << "v7:" << endl;
	for (auto i : v7)
		cout << i << " ";
	cout << endl;

	return 0;
}