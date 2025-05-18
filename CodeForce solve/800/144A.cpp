#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    int maxVal = -1, minVal = 101;
    int maxIdx = 0, minIdx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

       
        if (a[i] > maxVal) {
            maxVal = a[i];
            maxIdx = i;
        }

        
        if (a[i] <= minVal) {
            minVal = a[i];
            minIdx = i;
        }
    }

    int steps = maxIdx + (n - 1 - minIdx);

    
    if (minIdx < maxIdx)
        steps--;

    cout << steps;
    return 0;
}
/*Copy
10
Note
In the first sample the colonel will need to swap the first and second soldier and then the third and fourth soldier. That will take 2 seconds. The resulting position of the soldiers is (44, 33, 22, 11).

In the second sample the colonel may swap the soldiers in the following sequence:

(10, 10, 58, 31, 63, 40, 76)
(10, 58, 10, 31, 63, 40, 76)
(10, 58, 10, 31, 63, 76, 40)
(10, 58, 10, 31, 76, 63, 40)
(10, 58, 31, 10, 76, 63, 40)
(10, 58, 31, 76, 10, 63, 40)
(10, 58, 31, 76, 63, 10, 40)
(10, 58, 76, 31, 63, 10, 40)
(10, 76, 58, 31, 63, 10, 40)
(76, 10, 58, 31, 63, 10, 40)
(76, 10, 58, 31, 63, 40, 10)






Input: 5
Array: 10 20 30 10 40

max = 40 → index = 4
min = 10 → index = 3 (last 10)

ধরি: index:    0   1   2   3   4
    Array: 10  20  30  10  40

maxIdx = 4 → তাকে index 0 এ আনতে লাগে 4 swap
(40 ← 10, 30, 20, 10)

এই 4 swap করার সময় min (index 3) একধাপ ডানে সরে যাবে
মানে, এখন minIndex = 4 হয়ে যাবে

min কে পেছনে নিতে swap = (4 → 4) = 0
**আসলে লাগত 1 swap, কিন্তু আগেই সরে গেছে max এর জন্য**

তাই এখানে **1টা swap বেঁচে গেছে**

 তাই `steps--;` করতে হয়




*/