#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int k;
    cin >> k;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            flag = 1;
            cout << i << endl;
            break;
        }
    }

    if (flag == 0)
    {
        cout << -1;
    }
    return 0;
}