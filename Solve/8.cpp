#include <bits/stdc++.h>
using namespace std;
int main()
{
string str ;
cin>>str;
    vector<string> v;
 
    stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
 
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << endl;
return 0;
}


//split string in cpp by coma
//https://www.geeksforgeeks.org/program-to-parse-a-comma-separated-string-in-c/