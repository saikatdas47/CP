#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int k;
    cin >> n >> k;
    int d[k], b[k];
    for (int i = 0; i < k; i++)
    {
        cin >> d[i] >> b[i];
    }

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            if (d[j] > d[j + 1])
            {
                swap(d[j], d[j + 1]);
                swap(b[j], b[j + 1]);
            }
        }
    }
    // cout<<"........................";
    // for (int i = 0; i < k; i++)
    // {
    //     cout<<d[i]<<" "<<b[i]<<endl;
    // }
    bool flag = true;
    for (int i = 0; i < k; i++)
    {
        if (n > d[i])
        {
            n = n + b[i];
        }
        else
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}