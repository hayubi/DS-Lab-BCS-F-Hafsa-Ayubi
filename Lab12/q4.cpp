/*Question#4: You are developing a search feature for a large book database. Implement the KMP algorithm to search for a query string in the book’s content. Return all positions where the query occurs. 
Example:
Input: Text = ababababc
Pattern = abab
Output: [0, 2, 4]
Extra Challenge: Show the LPS (Longest Prefix Suffix) array used for the search.*/

#include <iostream>
#include <string>
using namespace std;

void computeLPSArray(const string &pattern, int lps[]) 
{
    int patlen = pattern.length();
    lps[0] = 0;
    int len = 0;
    int i = 1;

    while (i < patlen) 
    {
        if (pattern[i] == pattern[len]) 
        {
            len++;
            lps[i] = len;
            i++;
        } 
        else 
        {
            if (len != 0)
                len = lps[len-1];
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    string text = "ababababc";
    string pattern = "abab";

    int txtlen = text.length();
    int patlen = pattern.length();

    int lps[200];
    computeLPSArray(pattern, lps);

    cout << "LPS Array: [";
    for (int i=0; i<patlen; i++) 
    {
        cout << lps[i];
        if (i != patlen-1)
            cout << ", ";
    }
    cout << "]" << endl;

    int positions[200];
    int posCount = 0;
    int i=0;
    int j=0;

    while (i < txtlen) 
    {
        if (pattern[j] == text[i]) 
        {
            i++;
            j++;
        }

        if (j == patlen) 
        {
            positions[posCount++] = i-j;
            j = lps[j-1];
        } 
        else if (i<txtlen && pattern[j] != text[i]) 
        {
            if (j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }

    cout << "Output: [";
    for (int k=0; k<posCount; k++) 
    {
        cout << positions[k];
        if (k != posCount-1)
            cout << ", ";
    }
    cout << "]";
}