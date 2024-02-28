#include <iostream>
using namespace std;

bool checkPParity(string text);
int gcd(int x, int y);

struct Stack
{
    int capacity = 10;
    int data[10];
    int index = 0;

    void push(int value)
    {
        if(index < capacity)
            data[index++] = value;
        else
            cout << "Stack is full!" << endl;
    }

    int pop()
    {
        if(index > 0)
            return data[--index];
        else
        {
            cout << "Stack is empty!" << endl;
            return INT32_MIN;
        }
    }

    int top()
    {
        if(index > 0)
            return data[index - 1];
        else
        {
            cout << "Stack is empty!" << endl;
            return INT32_MIN;
        }
    }

    bool isEmpty()
    {
        return !index;
    }
};

int main() {
    string text = "([(text[])])({})(<>)";
    
    if (checkPParity(text))
        cout << "Correct text parity" << endl;
    else
        cout << "Incorrect text parity" << endl;
    
    cout << gcd(60, 24) << endl;

    return 0;
}

int gcd(int x, int y)
{
    if(y == 0)
        return x;

    gcd(y, x % y);
}

bool checkPParity(string text)
{
    Stack s;
    for (char c : text) 
    {
        if (c == '(' || c == '[' || c == '{' || c == '<')
            s.push(c);
        else if (c == ')') 
        {
            if (s.top() != '(') {
                return false;
            }
            s.pop();
        }
        else if (c == ']') 
        {
            if (s.top() != '[') {
                return false;
            }
            s.pop();
        }
        else if (c == '}') 
        {
            if (s.top() != '{') {
                return false;
            }
            s.pop();
        }
        else if (c == '>') 
        {
            if (s.top() != '<') {
                return false;
            }
            s.pop();
        }
        else 
        {
            continue;
        }
    }
    return true;
}