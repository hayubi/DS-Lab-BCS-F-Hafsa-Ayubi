/*Question#1: You are developing a text editor. Implement a function that searches for all occurrences of a user-provided keyword in a large document. Use the Brute Force algorithm to find and return the starting indices of the keyword in the document.
Example:
Input: Text = "the quick brown fox jumps over the lazy dog"
Pattern = "the"
Output: [0,31]
Extra Challenge: Count and return the total number of comparisons your algorithm makes.*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string txt = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    int txtlen = txt.length();
    int patlen = pattern.length();
    int positions[200];
    int posCount = 0;
    int comparisons = 0;

    for (int i=0; i <= txtlen-patlen; i++) 
    {
        int j=0;
        while (j < patlen) 
        {
            comparisons++;
            if (txt[i+j] != pattern[j])
                break;
            j++;
        }
        if (j == patlen)
            positions[posCount++] = i;
    }

    cout << "Output: [";
    for (int i=0; i<posCount; i++) 
    {
        cout << positions[i];
        if (i != posCount-1)
            cout << ", ";
    }
    cout << "]" << endl;
    cout << "Total Comparisons: " << comparisons;
}
