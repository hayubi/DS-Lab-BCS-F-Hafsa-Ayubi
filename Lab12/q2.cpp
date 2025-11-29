/*Question#2: You are building a plagiarism detection tool. Implement the Rabin-Karp algorithm to find whether a small snippet of text appears anywhere in a larger document. Return all positions where the snippet occurs. Assume you are using a simple hash function with a prime modulus of your choice. 
Example:
Input: Text = "Data structures and algorithms are fun. Algorithms make tasks easier."
Pattern = "Algorithms" 
Output: [27, 41]
Extra Challenge: Demonstrate the effect of hash collisions by printing any false-positive hash matches that are discarded.*/

#include <iostream>
#include <string>
using namespace std;

#define d 256
int main() 
{
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";
    int q = 101;

    int txtlen = text.length();
    int patlen = pattern.length();
    int positions[100];
    int posCount = 0;
    int collisions[100];
    int colCount = 0;

    if (patlen == 0 || patlen > txtlen)
        return 0;

    int p=0;
    int t=0;
    int h=1;

    for (int i=0; i < patlen-1; i++)
        h = (h*d) % q;

    for (int i=0; i<patlen; i++) 
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i=0; i <= txtlen-patlen; i++) 
    {

        if (p == t) 
        {
            bool match = true;
            for (int j=0; j<patlen; j++) 
            {
                if (text[i+j] != pattern[j]) 
                {
                    match = false;
                    break;
                }
            }

            if (match)
                positions[posCount++] = i;
            else
                collisions[colCount++] = i;
        }

        if (i < txtlen-patlen) 
        {
            t = (d * (t - text[i] * h) + text[i+patlen]) % q;
            if (t<0)
                t = t + q;
        }
    }

    if (colCount > 0) 
    {
        cout << "Hash Collision Detected At Window(s): ";
        for (int i=0; i<colCount; i++)
            cout << collisions[i] << " ";
        cout << "\n(These were discarded)\n\n";
    }

    cout << "Output: [";
    for (int i=0; i<posCount; i++) 
    {
        cout << positions[i];
        if (i != posCount-1)
            cout << ", ";
    }
    cout << "]";
}