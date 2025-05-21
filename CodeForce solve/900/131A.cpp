#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;

    bool all_upper = all_of(s.begin(), s.end(), [](char c)
                            { return isupper(c); });

    bool first_lower_rest_upper = islower(s[0]) && all_of(s.begin() + 1, s.end(), [](char c)
                                                          { return isupper(c); });

    if (all_upper)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        cout << s;
    }
    else if (first_lower_rest_upper == true)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s[0] = toupper(s[0]);
        cout << s;
    }
    else
    {
        cout << s;
    }
}
/*
নাম cAPS lOCK, মানে কেউ যেন Caps Lock চাপা অবস্থায় টাইপ করে ফেলছে ভুল করে 😅।

আমরা ধরে নিচ্ছি কেউ টাইপ করতে গিয়েছিলো “Hello”, কিন্তু হয়ে গেছে “hELLO” — কারণ caps lock অন ছিল। এখন আমাদের কাজ হচ্ছে ঠিক করে দেওয়া — যদি caps lock ভুলে অন হয়ে থাকে।

⸻

🔍 কীভাবে ধরবো caps lock ভুলে অন ছিল কিনা?

👉 Caps Lock ভুলে অন ছিল, যদি:
	1.	পুরো শব্দটাই uppercase (যেমন: HTTP)
	2.	প্রথম অক্ষর ছাড়া বাকি সব অক্ষর uppercase (যেমন: cAPS)

এই দুইটা কন্ডিশনের যেকোনো একটা হলে, আমরা পুরো word এর case উল্টে দেবো।
না হলে, word যেমন আছে তেমনই রাখবো।

⸻

🎯 উদাহরণ দিয়ে বুঝি:

Example 1:

Input: cAPS

➡ প্রথম অক্ষর: ছোট হরফ
➡ বাকি: সব বড় হরফ

✅ condition match করলো ⇒ সব letter এর case উল্টে দে ⇒ Caps

Output: Caps

⸻

Example 2:

Input: Lock

➡ প্রথম অক্ষর: বড়
➡ বাকি: ছোট

❌ কোন condition match করলো না ⇒ কিছু করবি না

Output: Lock

⸻

Example 3:

Input: hELLO

➡ প্রথম ছোট, বাকি বড়
✅ caps lock ভুলে অন ছিল ⇒ case উল্টে দে ⇒ Hello

Output: Hello

⸻

Example 4:

Input: Z

➡ একটাই letter ⇒ ছোট বা বড় যাই হোক, ধরা যাবে ভুল করে caps অন ছিল

✅ condition match ⇒ case পাল্টে দে ⇒ যদি ছোট থাকে, বড় করবি; বড় থাকলে ছোট
*/