#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k = n - 1;
    int p = 0;
    int s = 0, d = 0;
    bool turn = true; // true = Sereja's turn, false = Dima's turn

    while (p <= k)
    {
        int selected;
        if (a[p] >= a[k])
        {
            selected = a[p];
            p++;
        }
        else
        {
            selected = a[k];
            k--;
        }

        if (turn)
            s += selected;
        else
            d += selected;

        turn = !turn; //switch true to false or false to true
    }

    cout << s << " " << d << endl;
    return 0;
}