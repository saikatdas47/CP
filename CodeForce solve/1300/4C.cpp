#include <iostream>
#include <map>      // নাম কতবার এসেছে সেটা রাখার জন্য
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> database;  // নামের সাথে সংখ্যা রাখার জন্য

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        // যদি নাম আগে না থাকে
        if (database[name] == 0) {
            cout << "OK" << endl;
            database[name] = 1;  // এখন থেকে নাম ১ বার দেখা গেছে
        } else {
            // নতুন নাম তৈরি করো নাম + সংখ্যা
            string newName = name + to_string(database[name]);
            cout << newName << endl;

            // পুরোনো নামের সংখ্যা বাড়াও
            database[name]++;
            // নতুন নামকেও ডাটাবেজে রাখো
            database[newName] = 1;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> usernames;  // এখানে সব নাম রাখা হবে

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        int count = 0;
        bool found = false;

        // আগের সব নামের সাথে মিলিয়ে দেখো
        for (string existing : usernames) {
            if (existing == name || existing.find(name) == 0) {
                if (existing == name) found = true;

                // যদি name + number টাইপ থাকে, যেমন name1, name2
                if (existing.substr(0, name.size()) == name) {
                    string suffix = existing.substr(name.size());
                    bool isNumber = true;
                    for (char ch : suffix) {
                        if (!isdigit(ch)) {
                            isNumber = false;
                            break;
                        }
                    }
                    if (isNumber) {
                        count = max(count, stoi(suffix));
                    }
                }
            }
        }

        if (!found) {
            cout << "OK" << endl;
            usernames.push_back(name);
        } else {
            count++;
            string newName = name + to_string(count);
            cout << newName << endl;
            usernames.push_back(newName);
        }
    }

    return 0;
}
/*
C. Registration system
time limit per test5 seconds
memory limit per test64 megabytes
A new e-mail service "Berlandesk" is going to be opened in Berland in the near future. The site administration wants to launch their project as soon as possible, that's why they ask you to help. You're suggested to implement the prototype of site registration system. The system should work on the following principle.

Each time a new user wants to register, he sends to the system a request with his name. If such a name does not exist in the system database, it is inserted into the database, and the user gets the response OK, confirming the successful registration. If the name already exists in the system database, the system makes up a new user name, sends it to the user as a prompt and also inserts the prompt into the database. The new name is formed by the following rule. Numbers, starting with 1, are appended one after another to name (name1, name2, ...), among these numbers the least i is found so that namei does not yet exist in the database.

Input
The first line contains number n (1 ≤ n ≤ 105). The following n lines contain the requests to the system. Each request is a non-empty line, and consists of not more than 32 characters, which are all lowercase Latin letters.

Output
Print n lines, which are system responses to the requests: OK in case of successful registration, or a prompt with a new name, if the requested name is already taken.

Examples
inputCopy
4
abacaba
acaba
abacaba
acab
outputCopy
OK
OK
abacaba1
OK
inputCopy
6
first
first
second
second
third
third
outputCopy
OK
first1
OK
second1
OK
third1
*/