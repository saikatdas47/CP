// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     long int a = 1;
//     for (int i = 0; i < n; ++i)
//     {
//         a *= 5;
//     }
//     if (a < 10)
//     {
//         cout << "0" << a << endl;
//     }
//     else
//     {
//         cout << a % 100 << endl; //%10 1 digit, %100 2nd last digit
//     }

//     return 0;
// }
/* ata এই লুপে তুমি n বার 5 গুণ করছো, যেখানে n \leq 2 \times 10^{18}। এটি অবাস্তব — এত বড় লুপ চালানো সম্ভব নয়, এবং তোমার প্রোগ্রাম টাইম লিমিট পার করে ফেলছে।

⸻

✔ সমাধান (অবজারভেশন ভিত্তিক):

আমরা উপরে আলোচনা করেছি:
যেকোনো n \geq 2 হলে, 5^n এর শেষ দুই অঙ্ক সবসময় 25 হয়।
*/

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n >= 2)
        cout << "25" << endl;
    else
        cout << "05" << endl; // For n = 1 → 5^1 = 5 → last two digits = 05

    return 0;
}