#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s("123456789ABCDEF");

    cout << "befor test" << endl;
    cout << s << endl;

    for (char &c : s)
        c = 'X';

    cout << "after test" << endl;
    cout << s << endl;
    return 0;
}