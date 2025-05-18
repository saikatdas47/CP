#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int b=0;
    for (int i = 0; i < n; i++)
    {
       cin>>a[i];
       b=a[i]+b;

    }
    cout << fixed;
    cout.precision(11);
    cout << static_cast<double>(b) / n;
    
}