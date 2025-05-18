#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, p, q;
        cin >> n >> m >> p >> q;

        int total_segments = n - p + 1;
        long long total_segment_sum = 1LL * total_segments * q;

        // Total sum must be divisible by p and equal to m
        if (total_segment_sum % p == 0 && total_segment_sum / p == m)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}