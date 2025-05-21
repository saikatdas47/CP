#include <iostream>

using namespace std;

int main()
{
    string n, h, p;
    cin >> n >> h >> p;

    string combined = n + h;

    for (int i = 0; i < p.size(); ++i)
    {

        for (int j = 0; j < combined.size(); j++)
        {
            if (p[i] == combined[j])
            {

                p.erase(i, 1);
                combined.erase(j, 1);
                --i;
                --j;

            }
        }
    }

    if (combined.empty() && p.empty())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}