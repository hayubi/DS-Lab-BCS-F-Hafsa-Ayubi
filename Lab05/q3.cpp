/*Task 3:
1. Implement a C++ function sumTail(int n, int total) that calculates the sum
of numbers from 1 to n using tail recursion. The recursive call should be the last
operation in the function.
2. Implement another function sumNonTail(int n) that calculates the same sum
using non-tail recursion. This function should perform an operation (e.g., addition) after
the recursive call returns. Compare the two implementations and explain the difference
in their call stacks.*/

#include <iostream>
using namespace std;

int sumTail(int n, int total) 
{
    if (n==0)
        return total;
    return sumTail(n-1, total+n);
}

int sumNonTail(int n) 
{
    if (n==0)
        return 0;
    return n+sumNonTail(n-1);
}

int main() 
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << endl << "Tail Recursion: " << sumTail(num, 0) << endl;
    cout << "Non Tail Recursion: " << sumNonTail(num) << endl;
}
