/*Task # 4: Given an array of distinct integers, find using hashing if there are two pairs (a, b) and (c, d) such that
a+b = c+d, and a, b, c, and d are distinct elements. If there are multiple answers, then print any of
them.
Input: {3, 4, 7, 1, 2, 9, 8}
Output: (3, 8) and (4, 7)
Explanation: 3+8 = 4+7
Input: {3, 4, 7, 1, 12, 9};
Output: (4, 12) and (7, 9)
Explanation: 4+12 = 7+9
Input: {65, 30, 7, 90, 1, 9, 8};
Output: No pairs found*/
  
#include <iostream>
using namespace std;

struct Pair 
{
    int a;
    int b;
    bool used;
};

void findPairs(int arr[], int n) 
{
    Pair hash[2000];

    for (int i= 0; i < 2000; i++)
        hash[i].used = false;

    for (int i=0; i < n; i++) {
        for (int j= i+1; j < n; j++) {
            int sum=arr[i] + arr[j];
            if (!hash[sum].used) {
                hash[sum].a= arr[i];
                hash[sum].b= arr[j];
                hash[sum].used = true;
            }
            else {
                int x =hash[sum].a;
                int y =hash[sum].b;
                if (x != arr[i] && x != arr[j] &&
                    y != arr[i] && y != arr[j]) {
                    cout << "(" << x << ", " << y << ") and ("
                         << arr[i] << ", " << arr[j] << ")" << endl;
                    return;
                }
            }
        }
    }
    cout << "No pairs found" << endl;
}

int main() 
{
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    findPairs(arr1, 7);
    findPairs(arr2, 6);
    findPairs(arr3, 7);

}
