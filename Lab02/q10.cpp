/*Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numcategories;
    cout << "Enter the number of categories of books: ";
    cin >> numcategories;
    int **books = new int*[numcategories];
    int *numofbooks = new int[numcategories];
    string *categories = new string[numcategories];

    cout << "Enter " << numcategories << " categories: " << endl;
    for (int i=0; i<numcategories; i++)
    {
        cout << i+1 << ": ";
        cin >> categories[i];

        cout << "Enter number of books for " << i+1 << " category: ";
        cin >> numofbooks[i];

        books[i] = new int[numofbooks[i]];
        cout << "Enter book IDs: " << endl;
        for (int j=0; j<numofbooks[i]; j++)
        {
            cout << "Book " << j+1 << ": ";
            cin >> books[i][j];
        }
    }

    char choice;
    cout << "Do you want to search a book(y/n)? ";
    cin >> choice;

    if (choice != 'y')
    {
        for (int i=0; i<numcategories; i++)
        {
            delete[] books[i];
        }
        delete[] books;
        delete[] categories;
        delete[] numofbooks;
        return 0;
    }

    string searchcatg;
    bool found = false;
    int searchID;
    cout << "Enter the book ID: ";
    cin >> searchID;
    for (int i=0; i<numcategories; i++)
    {
        for (int j=0; j<numofbooks[i]; j++)
        {
            if (books[i][j] == searchID)
            {
                found = true;
                searchcatg = categories[i];
            }
        }
    }

    if (found == true)
        cout << "Book available. Category: " << searchcatg << endl;
    else
        cout << "Book not available." << endl;

    for (int i=0; i<numcategories; i++)
    {
        delete[] books[i];
    }
    delete[] books;
    delete[] categories;
    delete[] numofbooks;
}