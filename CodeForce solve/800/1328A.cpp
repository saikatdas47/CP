#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a[t],b[t];
    for (int i = 0; i < t; i++)
    {
         cin>>a[i]>>b[i];
    }

    for (int i = 0; i < t; i++)
    {
       if (a[i]%b[i]==0)
       {
        cout<<0<<endl;

       }
       else{
        cout<<b[i] - (a[i] % b[i])<<endl;
       }
       
    }
    
    
   
}