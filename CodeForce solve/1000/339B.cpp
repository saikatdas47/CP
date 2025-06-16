#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> b(w);
    for (int i = 0; i < w; i++)
    {
        cin >> b[i];
    }

    long long c = 0;
    int curr = 1; // Xenia starts at house 1

    for (int i = 0; i < w; i++)
    {
        int target = b[i];
        if (target >= curr)
        {
            c += (target - curr);
        }
        else
        {
            c += (n - curr + target); // clockwise round
        }
        curr = target;
    }

    cout << c << endl;

    return 0;
}