#include <bits/stdc++.h>

using namespace std;

int main()  
{  std::string s;
getline(cin,s);
  std::istringstream is( s );
    int n;
    int k=0;
    while( is >> n ) {
      k=k+n;
    }  cout<<k<<"\n";

}  

//prectise
//split string 
//https://www.javatpoint.com/how-to-split-strings-in-cpp
//split int from string
//https://stackoverflow.com/questions/3421817/splitting-int-from-a-string