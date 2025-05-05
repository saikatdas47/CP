/*
A. Wrong Subtraction
time limit per test1 second
memory limit per test256 megabytes
Little girl Tanya is learning how to decrease a number by one, but she does it wrong with a number consisting of two or more digits. Tanya subtracts one from a number by the following algorithm:

if the last digit of the number is non-zero, she decreases the number by one;
if the last digit of the number is zero, she divides the number by 10 (i.e. removes the last digit).
You are given an integer number 𝑛. Tanya will subtract one from it 𝑘 times. Your task is to print the result after all 𝑘 subtractions.

It is guaranteed that the result will be positive integer number.

Input
The first line of the input contains two integer numbers 𝑛 and 𝑘 (2≤𝑛≤109, 1≤𝑘≤50) — the number from which Tanya will subtract and the number of subtractions correspondingly.

Output
Print one integer number — the result of the decreasing 𝑛 by one 𝑘 times.

It is guaranteed that the result will be positive integer number.

Examples
inputCopy
512 4
outputCopy
50
inputCopy
1000000000 9
outputCopy
1
Note
The first example corresponds to the following sequence: 512→511→510→51→50.

Tanya-র subtraction logic:
	•	যদি number-এর last digit non-zero হয় → just -1.
	•	যদি last digit zero হয় → number টাকে 10 দিয়ে ভাগ করে দাও (last digit remove).

এভাবে k বার কাজটা করতে হবে।

⸻

🎯 উদাহরণ দিয়ে বোঝা যাক:

Input: 512 4

Steps:
	•	512 → last digit 2 → 511
	•	511 → last digit 1 → 510
	•	510 → last digit 0 → 51
	•	51 → last digit 1 → 50 

Output: 50

*/
#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int lastd=n%10;  //last digit 10 diye vag  kore vagshes tai 
        if(lastd!=0)
        {
            n=n-1; 
        }
        else
        {
            n=n/10;
        }
    }
    cout<<n<<endl;
    return 0;
}