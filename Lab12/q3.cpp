/*Question#3: You are designing a DNA sequence analyzer. Implement the Boyer-Moore algorithm to efficiently find a short DNA motif (pattern) in a long DNA strand. Return all starting positions of the motif in the strand. Example:
Input: DNA = ACGTACGTGACG 
Pattern = "ACG"
Output: [0, 4, 9]
Extra Challenge: Implement both the bad character and good suffix heuristics for optimal performance.*/

#include <iostream>
#include <string>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(const string &pattern, int badChar[]) 
{
    for (int i=0; i<NO_OF_CHARS; i++)
        badChar[i] = -1;
    for (int i=0; i<pattern.length(); i++)
        badChar[(int)pattern[i]] = i;
}

void computeSuffix(const string &pattern, int suffix[]) 
{
    int patlen = pattern.length();
    suffix[patlen-1] = patlen;
    int g = patlen-1;
    int f=0;

    for (int i = patlen-2; i >= 0; i--) 
    {
        if (i > g && suffix[i+patlen-1-f] < i-g)
            suffix[i] = suffix[i+patlen-1-f];
        else 
        {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && pattern[g] == pattern[g+patlen-1-f])
                g--;
            suffix[i] = f - g;
        }
    }
}

void goodSuffixHeuristic(const string &pattern, int goodSuffix[]) 
{
    int patlen = pattern.length();
    int suffix[200];
    computeSuffix(pattern, suffix);

    for (int i=0; i<patlen; i++)
        goodSuffix[i] = patlen;

    int j=0;
    for (int i = patlen-1; i >= 0; i--) 
    {
        if (suffix[i] == i+1) 
        {
            for (; j < patlen-1-i; j++)
                goodSuffix[j] = patlen-1-i;
        }
    }

    for (int i=0; i < patlen-1; i++)
        goodSuffix[patlen-1 - suffix[i]] = patlen-1-i;
}

int main() 
{
    string text = "ACGTACGTGACG";
    string pattern = "ACG";

    int n = text.length();
    int patlen = pattern.length();
    int badChar[NO_OF_CHARS];
    int goodSuffix[200];
    int positions[200];
    int posCount=0;

    badCharHeuristic(pattern, badChar);
    goodSuffixHeuristic(pattern, goodSuffix);

    int s=0;
    while (s <= n-patlen) 
    {
        int j = patlen-1;

        while (j >= 0 && pattern[j] == text[s+j])
            j--;

        if (j<0) 
        {
            positions[posCount++] = s;
            s = s + goodSuffix[0];
        } 
        else 
        {
            int badShift = j - badChar[(int)text[s+j]];
            int goodShift = goodSuffix[j];
            
            int shift;
            if (badShift > goodShift)
                shift = badShift;
            else
                shift = goodShift;

            if (shift < 1)
                shift = 1;

            s = s + shift;
        }
    }

    cout << "Output: [";
    for (int i=0; i < posCount; i++) 
    {
        cout << positions[i];
        if (i != posCount-1)
            cout << ", ";
    }
    cout << "]";
}