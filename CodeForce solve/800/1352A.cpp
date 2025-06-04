#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    while (n--)
    {

        cin >> a;

     
        int c = 0, s = 0;
        stack<int> st;
        int p = 1;

     /*
    •	উদাহরণ: n = 5079
	•	9 × 1 = 9
	•	7 × 10 = 70
	•	0 × 100 = skip //==0 hole stack e nibo na + count o korbo na
	•	5 × 1000 = 5000
→ উত্তর: 3টি round number → 5000 70 9
*/
        for (int i = a; i >0; i= a /= 10 )  //last digit acces korar niyom
        {
            int digit = a % 10;
            // cout << digit << " ";
            // a /= 10; 

            s = digit * p;
            p = p * 10;
            
            if (s != 0)
            {
                c++;
                st.push(s);
            }
        }
        cout << c << endl;
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    return 0;
}


/*
তোমাকে একটি সংখ্যা n দেওয়া হবে, তোমাকে round number দিয়ে সেটিকে গঠন করতে হবে এবং যত কম সংখ্যক round number ব্যবহার করা যায়, তত ভালো।

🔍 Round Number কী?

যেসব সংখ্যায় শুধুমাত্র একটিমাত্র non-zero digit থাকে এবং বাকি সব 0 — যেমনঃ
1, 10, 200, 9000 এগুলো round number।
110, 707 এগুলো না।

⸻

✅ সমাধান কৌশল (Logic):
	1.	তুমি সংখ্যা n এর প্রতিটি digit কে চেক করবে।
	2.	যদি digit 0 না হয়, তাহলে সেটা তার position অনুযায়ী multiply করে round number তৈরি করবে।
উদাহরণঃ
	•	n = 5009
	•	→ 5 thousands = 5000,
	•	→ 0 hundreds = skip,
	•	→ 0 tens = skip,
	•	→ 9 units = 9
	•	ফলাফল: 5000 + 9

⸻


*/