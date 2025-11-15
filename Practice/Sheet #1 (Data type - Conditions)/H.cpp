#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long int a, b;
    cin >> a >> b;
    float d = (float)a / b; // force floating-point division
    int c = a / b;
    int flr, clg, rnd;

    if (d == c)
    {
        rnd = c;
        flr = c;
        clg = c;
    }
    else if (d < c + 0.5)
    {
        rnd = c;
        flr = c;
        clg = c + 1;
    }
    else
    {
        rnd = c + 1;
        flr = c;
        clg = c + 1;
    }

    cout << "floor " << a << " / " << b << " = " << flr << endl;
    cout << "ceil " << a << " / " << b << " = " << clg << endl;

    cout << "round " << a << " / " << b << " = " << rnd << endl;

    return 0;
}

/*
H. Two numbers
time limit per test1 second
memory limit per test256 megabytes
Given 2 numbers 𝐴 and 𝐵. Print floor, ceil and round of 𝐴/𝐵

Note:

Floor: Is a mathematical function that takes a real number 𝑋 and its output is the greatest integer less than or equal to 𝑋.
Ceil: Is a mathematical function that takes a real number 𝑋 and its output is the smallest integer larger than or equal to 𝑋.
Round: Is a mathematical function that takes a real number 𝑋 and its output is the closest integer to that number 𝑋.

For more clarification visit the links in the notes below.

Input
Only one line containing two numbers 𝐴 and 𝐵 (1≤𝐴,𝐵≤103)
Output
Print 3 lines that contain the following in the same order:

"floor 𝐴 / 𝐵 = Floor result" without quotes.
"ceil 𝐴 / 𝐵 = Ceil result" without quotes.
"round 𝐴 / 𝐵 = Round result" without quotes.
Examples
inputCopy
10 3
outputCopy
floor 10 / 3 = 3
ceil 10 / 3 = 4
round 10 / 3 = 3
inputCopy
10 4
outputCopy
floor 10 / 4 = 2
ceil 10 / 4 = 3
round 10 / 4 = 3
inputCopy
10 6
outputCopy
floor 10 / 6 = 1
ceil 10 / 6 = 2
round 10 / 6 = 2
Note
Links:

For Rounding method visit: https://www.mathsisfun.com/numbers/rounding-methods.html.
For Flooring and Ceiling method visit: https://www.mathsisfun.com/sets/function-floor-ceiling.html.



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    float d = (float)a / b; // force floating-point division
    int flr = floor(d);
    int clg = ceil(d);
    int rnd = round(d);

    cout << "floor " << a << " / " << b << " = " << flr << "\n";
    cout << "ceil " << a << " / " << b << " = " << clg << "\n";
    cout << "round " << a << " / " << b << " = " << rnd << "\n";

    return 0;
}
    
*/