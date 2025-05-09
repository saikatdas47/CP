/*
এই প্রবলেমটা একদম classic – একটা বছর দেওয়া থাকবে, ধরো y (যেমন 1987), আর তোমাকে খুঁজে বের করতে হবে এর পরবর্তী এমন একটা বছর যেটার সব digit আলাদা (distinct)।

⸻

🧠 উদাহরণ দিয়ে বুঝি:
    •	ইনপুট: 1987
    •	এর পরের বছর: 1988 → ❌ (digit 8 দুইবার)
    •	এরপর: 1989 → ✅ (digits: 1, 9, 8, 9 → ❌ again 9 repeats)
    •	এরপর: 1990 → ❌
    •	…
    •	অবশেষে: 2013 → ✅ ✅ ✅ সব digit ভিন্ন — উত্তর ✔️

⸻

🔁 কিভাবে কাজ করবে:

তোমাকে একটা loop চালাতে হবে, যেটা পরপর বছরের মান বাড়িয়ে যাবে যতক্ষণ না পর্যন্ত তুমি এমন একটা বছর পাও যেটার সব digit unique।

⸻

type cast
 string s = "1232";
    int num = stoi(s); // string to int
    num = num + 1;     // increment
    s = to_string(num); // int to string
    cout << s << endl;  // Output: 1233
    return 0;

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int y;
    cin >> y;
    y++; 

    while (true) {
        string s = to_string(y);
        if (s[0] != s[1] && s[0] != s[2] && s[0] != s[3] &&
            s[1] != s[2] && s[1] != s[3] &&
            s[2] != s[3]) {
            cout << y << endl;
            break;
        }
        y++;
    }

    return 0;
}