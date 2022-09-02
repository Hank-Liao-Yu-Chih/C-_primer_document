#include <iostream>
#include <string>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void swap(int &i, int &j)
{
	int tmp;

	tmp = i;
	i = j;
	j = tmp;
}

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;				// 紀錄第一次出現
			++occurs;
		}
	}
	return ret;
}

int main()
{
	int A = 10;
	int B = 20;
	string s1 = "Hello";
	string s2 = "AAAAAA";
	string s3 = "HAHA hello you!!";
	char c = 'l';
	string::size_type ret;
	string::size_type occurs;

	cout << "A : " << A << ",B : " << B << endl;
	swap(A, B);
	cout << "A : " << A << ",B : " << B << endl;

	cout << isShorter(s1, s2) << endl;

	ret = find_char(s3, c, occurs);
	cout << "ret : " << ret << ", occurs : " << occurs << endl;
	return 0;
}
