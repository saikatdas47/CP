/*
একটা স্ট্রিং (string) আছে, যেটা ০ আর ১ দিয়ে বানানো।
    •	0 মানে এক দলের প্লেয়ার (ধর লাল দল),
    •	1 মানে আরেক দলের প্লেয়ার (ধর নীল দল)।

তুই এই স্ট্রিং থেকে দেখতে চাস:

কোন দল একসাথে পরপর ৭ জন বা তার বেশি প্লেয়ার নিয়ে লাইন ধরে দাঁড়িয়ে আছে কিনা।

যদি এমন দেখা যায় — তাহলে ওই অবস্থাকে “dangerous” বলা হয়।
//main prb kono string er moddhe kono ekta sub string khuja jeta ami index dhore korle boro hobe/
tai ata find() use korte hobe
niche example daoya ache comment e.
*/
//index dhore korle ja hoy

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int c = 0;
    char prev = s[0];
    int flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == prev)
        {
            c++;
            if (c == 6)
            {
                flag = 1;
                break;
            }
        }
        else
        {
            prev = s[i];
            c = 0;
        }
    }

    if (flag == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    if(s.find("0000000") != string::npos || s.find("1111111") != string::npos) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
    string::npos হচ্ছে একটা special constant, যেটা basically বলে —

“আমি কিছু খুঁজে পাইনি।”

এটা একটা বিরাট বড় unsigned মান (usually -1 বা 4294967295),
যেটা string এর কোনো valid position না — অর্থাৎ: “no position”।

ধর,  যদি s.find("0000000") করিস — মানে s নামের স্ট্রিংয়ের মধ্যে "0000000" খুঁজছিস।
	•	যদি "0000000" পায়, তাহলে সেটা তার starting index দিয়ে দিবে।
	•	আর না পেলে, s.find() ফিরিয়ে দিবে string::npos।

*/