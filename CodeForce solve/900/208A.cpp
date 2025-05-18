#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    string d = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {
            i = i + 2;
            d += ' ';
        }
        else{
            d =d+ s[i];
        }
    }
    cout<<d;

}
/*Vasya একজন DJ, এবং সে পুরনো গানগুলোকে “dubstep” স্টাইলে remix করে। এই remix করার সময় সে একটা টেকনিক ফলো করে — সে প্রতিটা শব্দের মাঝে, শুরুর আগে আর শেষের পরে যত খুশি “WUB” বসায়। তারপর সবগুলো শব্দ একসাথে জোড়া দিয়ে একটা বড় স্ট্রিং বানায়।

তোর কাজ হচ্ছে: ওই remix করা স্ট্রিং দেখে মূল গানটা বের করা — মানে remix করার আগে গানটায় কী কী শব্দ ছিল, সেগুলো ঠিকঠাক সবার সামনে এনে দেওয়া।

⸻

উদাহরণ ১:

Input:
WUBWUBABCWUB
Breakdown:
	•	WUB + WUB + ABC + WUB
	•	Remix করার আগে মূল গান: ABC
Output:
ABC

⸻

উদাহরণ ২:

Input:
WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB
Breakdown:
	•	Remix করা গানটা থেকে WUB গুলো বাদ দিলে বা স্পেসে ভাঙলে পাবে:
	•	WE ARE THE CHAMPIONS MY FRIEND
Output:
WE ARE THE CHAMPIONS MY FRIEND
*/