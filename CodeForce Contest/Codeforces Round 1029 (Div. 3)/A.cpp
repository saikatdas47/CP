#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int d, k;
        cin >> d >> k;
        int a[d];
        for (int i = 0; i < d; i++)
        {
            cin >> a[i];
        }

       
        for (int i = 0; i < d; i++)
        {
            if (a[i] == 1)
            {
                for (int p = i; p < i + k && p < d; p++)
                {
                    a[p] = 0;
                }
                break;
            }
        }

       
        int sum = 0;
        for (int i = 0; i < d; i++)
        {
            sum += a[i];
        }

        if (sum == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}