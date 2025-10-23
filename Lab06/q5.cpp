/*Task 5 – Infix to Postfix Conversion using Stack
Write a program to convert an infix expression into postfix form using a stack. Also, evaluate the
postfix expression afterward.*/

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
        Stack(int cap=0)
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
            if (top<0)
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

int precedence(char c)
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

string infixToPostfix(string infix)
{
    string postfix = "";
    Stack s(infix.length());

    for (int i=0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (isdigit(c)) //operand
        { 
            while (i < infix.length() && isdigit(infix[i]))
            {
                postfix = postfix + infix[i];
                i++;
            }
            postfix = postfix + ' ';
            i--;
        }
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (!s.empty() && s.peek() != '(')
            {
                postfix = postfix + s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.peek()))
            {
                postfix = postfix + s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())  //remaining oprtrs
        postfix = postfix + s.pop();

    return postfix;
}

double evaluatePostfix(const string &postfix)
{
    Stack val(100);
    for (int i=0; i < postfix.length(); i++)
    {
        char c = postfix[i];
        if (c == ' ')  //skip space
            continue;
        else if (isdigit(c)) //operand
        {
            double num = 0;
            while (i < postfix.length() && isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            val.push(num);
            i--;
        }
        else
        {
            double val2 = val.pop();
            double val1 = val.pop();

            switch (c)
            {
            case '+':
                val.push(val1 + val2);
                break;
            case '-':
                val.push(val1 - val2);
                break;
            case '*':
                val.push(val1 * val2);
                break;
            case '/':
                val.push(val1 / val2);
                break;
            case '^':
                val.push(pow(val1, val2));
                break;
            }
        }
    }
    return val.pop();
}

void solution()
{
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    double result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;
}

int main()
{
    solution();
}