//Mishka and Game
#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n;
    int a = 0, b = 0 ,  x = 0, y = 0;  
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > b) {
            x++;
        } else if (b > a) {
            y++;
        }


} 
if(x>y){
    cout << "Mishka" << endl;
}
else if(x<y){
    cout << "Chris" << endl;
}
else{
    cout << "Friendship is magic!^^" << endl;
}  
}