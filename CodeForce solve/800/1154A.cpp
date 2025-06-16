#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> x(4);
    for (int i = 0; i < 4; ++i)
        cin >> x[i];

    sort(x.begin(), x.end());

    int a = x[3] - x[2];
    int b = x[3] - x[1];
    int c = x[3] - x[0];

    cout << a << " " << b << " " << c << endl;

    return 0;
}