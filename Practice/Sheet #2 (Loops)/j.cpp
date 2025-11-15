#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int k = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                k = 1; // kono ektar shate vagshes 0 pailam mane prime na. than break kore disi cz ami amar answer peye gesi. noyto complexity barbe
                break;
            }
        }
        if (k == 0)
        {
            cout << i << " ";
        }
        k = 0;
    }

    return 0;
}

/*
1 to n 
number porjonto joto prime number ache ta print 
*/