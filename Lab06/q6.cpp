/*Task 6 – Infix to Prefix Conversion using Stack
Write a program to convert an infix expression into prefix form using stack rules.
1. Include operator precedence and associativity handling.
2. Evaluate the prefix expression as well.*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack
{
    public:
        char *arr;
        int capacity;
        int top;

        Stack(int cap = 0)
        {
            capacity = cap;
            top = -1;
            arr = new char[capacity];
        }

        bool empty() { return top == -1; }

        void push(char n)
        {
            if (top == capacity-1)
            {
                cout << "Stack overflow" << endl;
                return;
            }
            arr[++top] = n;
        }

        char pop()
        {
            if (top < 0)
            {
                cout << "Stack underflow" << endl;
                return '\0';
            }
            return arr[top--];
        }

        char peek()
        {
            if (top<0)
                return '\0';
            return arr[top];
        }

        ~Stack()
        {
            delete[] arr;
            arr = nullptr;
        }
};

int getPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPrefix(string infix)
{
    string prefix = "";
    Stack st(infix.length());

    for (int i = infix.length()-1; i >= 0; i--)
    {
        char c = infix[i];
        if (isalnum(c))
            prefix = c + prefix;
        else if (c == ')')
            st.push(c);
        else if (c == '(')
        {
            while (!st.empty() && st.peek() != ')')
            {
                prefix = st.pop() + prefix;
            }
            if (!st.empty())
                st.pop(); 
        }
        else if (isOperator(c))
        {
            while (!st.empty() && getPrecedence(st.peek()) >= getPrecedence(c))
            {
                prefix = st.pop() + prefix;
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        prefix = st.pop() + prefix;
    }
    return prefix;
}

double evaluatePrefix(const string &prefix)
{
    double stack[100];
    int top = -1;

    for (int i = prefix.length()-1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isdigit(c))
        {
            stack[++top] = c-'0';
        }
        else if (isOperator(c))
        {
            double val1 = stack[top--];
            double val2 = stack[top--];

            switch (c)
            {
                case '+':
                    stack[++top] = val1 + val2;
                    break;
                case '-':
                    stack[++top] = val1 - val2;
                    break;
                case '*':
                    stack[++top] = val1 * val2;
                    break;
                case '/':
                    stack[++top] = val1 / val2;
                    break;
                case '^':
                    stack[++top] = pow(val1, val2);
                    break;
            }
        }
    }
    return stack[top];
}

void solution()
{
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    double result = evaluatePrefix(prefix);
    cout << "Result = " << result << endl;
}

int main()
{
    solution();
}