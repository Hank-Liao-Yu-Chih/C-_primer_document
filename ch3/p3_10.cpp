#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    while(getline(cin, line))
    {
        string result;
        cout << "original line is :" <<  line << endl;
        for (decltype(line.size()) index = 0; index != line.size(); ++index)
        {
            if (ispunct(line[index]))
                continue;
            result += line[index];
        }
        cout << "modify line is :" << result << endl;
    }
    return 0;
}