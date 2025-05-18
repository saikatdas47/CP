// #include <iostream>
// using namespace std;
// int main()
// {
//     long long  n, k;
//     cin >> n >> k;
//     long long s[n];
//     long long km = 1;
//     if (n % 2 == 0)
//     {
//         for (long long i = 0; i < n / 2; i++)
//         {
//             s[i] = km;
//             km = km + 2;
//         }
//         km = 2;
//         for (long long i = (n / 2); i < n; i++)
//         {
//             s[i] = km;
//             km = km + 2;
//         }
//         // for (int i = 0; i < n; i++)
//         // {
//         //     cout << s[i];
//         // }
//         cout << s[k-1];
//     }
//     else
//     {
//           for (long long i = 0; i < (n / 2)+1; i++)
//         {
//             s[i] = km;
//             km = km + 2;
//         }
//         km = 2;
//         for (long long i = (n / 2)+1; i < n; i++)
//         {
//             s[i] = km;
//             km = km + 2;
//         }
//          // for (int i = 0; i < n; i++)
//         // {
//         //     cout << s[i];
//         // }
//          cout << s[k-1];
//     }

   
// }
/*
এই সমস্যাটা একদম গাণিতিক ঘরানার। Volodya সব n সংখ্যাকে দুটো ভাগে সাজিয়েছে—আগে সব odd সংখ্যা (১ থেকে n এর মধ্যে), তারপর সব even সংখ্যা (১ থেকে n এর মধ্যে)। এখন তোমাকে বলা হয়েছে, সেই নতুন সাজানো সিরিজে k-তম সংখ্যাটি কত?

ধরো, n = 10। তাহলে Volodya যেভাবে সাজাবে:
Odd numbers: 1, 3, 5, 7, 9
Even numbers: 2, 4, 6, 8, 10
Full sequence: 1 3 5 7 9 2 4 6 8 10

এখন যদি k = 3 হয়, তাহলে উত্তর হবে 5।
আর যদি k = 7 হয়, তাহলে দেখা যাচ্ছে সেটা হচ্ছে even part-এর 2য় ইনডেক্সে থাকা 4।

এইভাবে চিন্তা করো—প্রথমে কতগুলো odd সংখ্যা থাকবে?
n সংখ্যার মধ্যে মোট (n + 1)/2 টা odd সংখ্যা থাকে (কারণ একটা odd-এর পর একটা even থাকে)।
এখন যদি k এই রেঞ্জের মধ্যে পড়ে, মানে যদি k ≤ (n + 1)/2, তাহলে k-তম সংখ্যা হবে k-th odd number, অর্থাৎ 2k - 1।
আর যদি k এই রেঞ্জের বাইরে পড়ে, তাহলে তুমি even part-এ চলে গেছো, সেক্ষেত্রে k-th সংখ্যাটি হবে:
2 * (k - (n + 1)/2) (কারণ তুমি even part-এর k - odd_count তম সংখ্যা চাচ্ছো)

উদাহরণ ১:
n = 10, k = 3
odd_count = (10 + 1)/2 = 5
3 ≤ 5 → তাহলে উত্তর হবে 2×3 - 1 = 5

উদাহরণ ২:
n = 7, k = 7
odd_count = (7 + 1)/2 = 4
7 > 4 → তাহলে উত্তর হবে 2 × (7 - 4) = 6

টাইম কমপ্লেক্সিটি: O(1), কারণ শুধু গাণিতিক হিসাব
স্পেস কমপ্লেক্সিটি: O(1)

হিন্ট: প্রথমে odd সংখ্যা কয়টা আছে সেটা বের করো (n + 1)/2 দিয়ে, তারপর দেখে নাও k কোথায় পড়ছে—odd না even ভাগে। তারপর 2k - 1 বা 2*(k - odd_count) হিসাব করলেই উত্তর।

এইটা brute force দিয়ে করলে Time Limit Exceeded দিবে, কারণ n অনেক বড় (১০^১২ পর্যন্ত)। এজন্য গাণিতিকভাবে হিসাব করাই একমাত্র পথ।
*/
#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long odd_count = (n + 1) / 2;

    if (k <= odd_count)
        cout << 2 * k - 1 << endl;
    else
        cout << 2 * (k - odd_count) << endl;

    return 0;
}