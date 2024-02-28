#include <iostream>
using namespace std;

struct Stack
{
    int capacity = 3;
    int data[3];
    int index = 0;

    void push(int value)
    {
        if(index < capacity)
            data[index++] = value;
        else
            cout << "Stack is full!" << endl;
    }
    int get();
};

int main() {
    Stack s;

    return 0;
}