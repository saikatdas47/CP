#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int c[n];
    int c0 = 0;
    int c1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i] = a[i] % 2;
        if (c[i] == 0)
        {
            c0++;
        }
        else if (c[i] == 1)
        {
            c1++;
        }
    }
    if (c0 > c1)
    {
        for (int i = 0; i < n; i++)
        {
            if (c[i] == 1)
            {
                cout << i + 1;
                break; //pele loop off kore daoya valo time complexity kombe
            }
        }
    }
    else if (c1 > c0)
    {
        for (int i = 0; i < n; i++)
        {
            if (c[i] == 0)
            {
                cout << i + 1;
                break;
            }
        }
    }

    return 0;
}
/*
A. IQ test
time limit per test2 seconds
memory limit per test256 megabytes
Bob is preparing to pass IQ test. The most frequent task in this test is to find out which one of the given n numbers differs from the others. Bob observed that one number usually differs from the others in evenness. Help Bob — to check his answers, he needs a program that among the given n numbers finds one that is different in evenness.

Input
The first line contains integer n (3 ≤ n ≤ 100) — amount of numbers in the task. The second line contains n space-separated natural numbers, not exceeding 100. It is guaranteed, that exactly one of these numbers differs from the others in evenness.

Output
Output index of number that differs from the others in evenness. Numbers are numbered from 1 in the input order.

Examples
inputCopy
5
2 4 7 8 10
outputCopy
3
inputCopy
4
1 2 1 1
outputCopy
2
*/