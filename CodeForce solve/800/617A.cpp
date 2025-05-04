#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[5] = {1, 2, 3, 4, 5};
    int steps = 0;

    for (int i = 4; i >= 0; i--)
    {
        while (n >= a[i])
        {
            steps =steps + n / a[i]; //12/5=2 vagfol and 12%5=2 vagshes vagfol holo step number r vagshes new distance
            //cout<<steps<<endl;
            n = n % a[i];   
            //cout<<n<<endl;   
        }
    }

    cout << steps << endl;
    return 0;
}


/*A. Elephant
time limit per test1 second
memory limit per test256 megabytes
An elephant decided to visit his friend. It turned out that the elephant's house is located at point 0 and his friend's house is located at point x(x > 0) of the coordinate line. In one step the elephant can move 1, 2, 3, 4 or 5 positions forward. Determine, what is the minimum number of steps he need to make in order to get to his friend's house.

Input
The first line of the input contains an integer x (1 ≤ x ≤ 1 000 000) — The coordinate of the friend's house.

Output
Print the minimum number of steps that elephant needs to make to get from point 0 to point x.

Examples
inputCopy
5
outputCopy
1
inputCopy
12
outputCopy
3
Note
In the first sample the elephant needs to make one step of length 5 to reach the point x.

In the second sample the elephant can get to point x if he moves by 3, 5 and 4. There are other ways to get the optimal answer but the elephant cannot reach x in less than three moves.*/