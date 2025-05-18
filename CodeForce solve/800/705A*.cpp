#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        if (i % 2 == 0)
            cout << "I hate ";
        else
            cout << "I love ";

        if (i == x - 1)
            cout << "it";
        else
            cout << "that ";
    }
    return 0;
}
/*
একটি সংখ্যা n দেওয়া হবে, যেটি বোঝায় Hulk-এর মনের কতটি স্তর আছে — একেকটা স্তর একেকটা অনুভূতির। অনুভূতিগুলো নির্দিষ্টভাবে চলে: প্রথমটা “I hate”, তারপর “I love”, 
তারপর আবার “I hate”, তারপর “I love” — এভাবে পালা করে চলবে। প্রতিটি অনুভূতির মাঝে থাকবে “that”, এবং সবশেষে থাকবে “it”। উদাহরণ দিয়ে বললে, যদি n = 1 হয়,
 তাহলে শুধু একটি অনুভূতি, তাই output হবে “I hate it”। যদি n = 2, তাহলে হবে “I hate that I love it” — কারণ hate → love, এবং শেষে it। আর যদি n = 3, 
 তাহলে হবে “I hate that I love that I hate it” — তিনটি অনুভূতির লেয়ার: hate → love → hate। মূলত প্রতি সংখ্যার জায়গায় alternately hate/love বসবে, মাঝে 
 “that”, আর শেষে “it” বসবে একবারই। টাইম কমপ্লেক্সিটি এখানে O(n) — কারণ n বার loop করতে হবে প্রতিটি অনুভূতির জন্য। স্পেস কমপ্লেক্সিটিও O(n) যদি তুমি স্ট্রিং জোগাড় করে জমাও।
  হেল্পফুল হিন্ট হলো — তুমি যেহেতু alternately hate/love বসাচ্ছো, তাই index (1-based বা 0-based) দেখে ঠিক করতে পারো কোনটাতে hate, কোনটাতে love বসবে। মনে রাখো —
   শেষে শুধু “it” বসবে, সেটাকে loop-এর বাইরে করলেও চলে।

*/