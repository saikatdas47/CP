//Next Round
/*. Next Round
time limit per test3 seconds
memory limit per test256 megabytes
"Contestant who earns a score equal to or greater than the k-th place finisher's score will advance to the next round, as long as the contestant earns a positive score..." — an excerpt from contest rules.

A total of n participants took part in the contest (n ≥ k), and you already know their scores. Calculate how many participants will advance to the next round.

Input
The first line of the input contains two integers n and k (1 ≤ k ≤ n ≤ 50) separated by a single space.

The second line contains n space-separated integers a1, a2, ..., an (0 ≤ ai ≤ 100), where ai is the score earned by the participant who got the i-th place. The given sequence is non-increasing (that is, for all i from 1 to n - 1 the following condition is fulfilled: ai ≥ ai + 1).

Output
Output the number of participants who advance to the next round.

Examples
inputCopy
8 5
10 9 8 7 7 7 5 5
outputCopy
6
inputCopy
4 2
0 0 0 0
outputCopy
0
Note
In the first example the participant on the 5th place earned 7 points. As the participant on the 6th place also earned 7 points, there are 6 advancers.

In the second example nobody got a positive score.

এইটা একটা কনটেস্ট বা প্রতিযোগিতা। ধর, মোট n জন প্রতিযোগী অংশ নিয়েছে। তাদের প্রত্যেকের স্কোর দেওয়া আছে — এবং এগুলো আগে থেকেই সাজানো, মানে বড় থেকে ছোট (non-increasing order)।

তাদের মধ্যে শুধুমাত্র সেইসব প্রতিযোগীরা পরবর্তী রাউন্ডে যাবে, যারা:
	1.	k-তম স্থানে থাকা প্রতিযোগীর স্কোরের সমান বা বেশি স্কোর পায়
	2.	স্কোর অবশ্যই পজিটিভ (positive) হতে হবে
    
    প্রথম লাইন:
	•	n → মোট প্রতিযোগীর সংখ্যা
	•	k → যে অবস্থানের স্কোরকে আমরা থ্রেশহোল্ড ধরি (যার চেয়ে কম স্কোর থাকলে বাদ পড়বে)

দ্বিতীয় লাইন:
	•	n টা সংখ্যা → প্রতিযোগীদের স্কোর (যেগুলা বড় থেকে ছোট সাজানো)
    8 5  
10 9 8 7 7 7 5 5

	•	এখানে n = 8, k = 5
	•	৫ নম্বর প্রতিযোগীর স্কোর = 7
	•	এখন, যারা 7 বা তার বেশি স্কোর পেয়ে‌ছে এবং স্কোর > 0, তারা সবাই পরবর্তী রাউন্ডে যাবে
তুই যা বের করবি:

✅ k-তম স্কোর বের কর
✅ এরপর চেক কর, কে কে সেই স্কোর বা তার বেশি পেয়েছে
✅ কিন্তু শুধুমাত্র তাদের কাউন্ট করবি যাদের স্কোর > 0
*/
#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int scores[n];
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    int threshold = scores[k - 1]; // k-th place score 0 index theke start
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (scores[i] >= threshold && scores[i] > 0) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
// Time complexity: O(n)
// Space complexity: O(n)
