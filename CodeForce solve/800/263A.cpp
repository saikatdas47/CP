/*A. Beautiful Matrix
time limit per test2 seconds
memory limit per test256 megabytes
You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one. Let's index the matrix rows by numbers from 1 to 5 from top to bottom, let's index the matrix columns by numbers from 1 to 5 from left to right. In one move, you are allowed to apply one of the two following transformations to the matrix:

Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for some integer i (1 ≤ i < 5).
Swap two neighboring matrix columns, that is, columns with indexes j and j + 1 for some integer j (1 ≤ j < 5).
You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell that is on the intersection of the third row and the third column). Count the minimum number of moves needed to make the matrix beautiful.

Input
The input consists of five lines, each line contains five integers: the j-th integer in the i-th line of the input represents the element of the matrix that is located on the intersection of the i-th row and the j-th column. It is guaranteed that the matrix consists of 24 zeroes and a single number one.

Output
Print a single integer — the minimum number of moves needed to make the matrix beautiful.

Examples
inputCopy
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
outputCopy
3
inputCopy
0 0 0 0 0
0 0 0 0 0
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
outputCopy
1


Input:
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

Output: 3
	1.	ম্যাট্রিক্স স্ক্যান করবো, কোথায় 1 আছে সেটা খুঁজে বের করবো।
	2.	তারপর |x - 2| + |y - 2| হিসেব করবো → এটা হলো Manhattan distance বা কতগুলো row/column swap লাগবে।
(1 আছে position (1,4) → চাই (2,2) →  |1-2| + |4-2| = 1+2 = 3 moves)



*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main() {
    int matrix[5][5];
    int x, y;


    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        cin>> matrix[i][j];
        if (matrix[i][j] == 1)
        {
          x = i;
          y = j;
        }
      }
      
    }
    // index where i found 1 is (x,y)
//our terget 5x5 matrix center which index is (2,2)
    int moves=abs(x-2)+abs(y-2);
    
    cout << moves << endl;

    return 0;
}