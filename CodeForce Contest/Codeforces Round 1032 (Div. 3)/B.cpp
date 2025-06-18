#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        bool f = false;
        for (int i = 1; i < n - 1; ++i)
        {
            char b = s[i];
            string ac = s.substr(0, i) + s.substr(i + 1);
            if (ac.find(b) != string::npos)
            {
                f = true;
                break;
            }
        }

        cout << (f ? "Yes" : "No") << '\n';
    }
    return 0;
}