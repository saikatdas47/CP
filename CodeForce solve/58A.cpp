// Chat room
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    string target = "hello";
    int j = 0;
  
        cin >> s;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == target[j])
            {
                j++;
            }
        }

        if (j == target.length())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    

    return 0;
}