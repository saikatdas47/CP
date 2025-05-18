#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int s[4];
    for (int i = 0; i < 4; i++)
    {

        cin >> s[i];
    }
    int c = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (s[i] == s[j])
            {
                c++;
                break;
            }
        }
    }


    cout << c;
}