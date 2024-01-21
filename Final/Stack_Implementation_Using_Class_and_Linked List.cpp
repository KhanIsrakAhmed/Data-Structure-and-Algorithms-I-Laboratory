//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    08-08-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "This stack us Overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "This Stack is UnderFlow" << endl;
        }
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "This stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        if (top < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(5);
    s.push(12);
    s.push(24);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    cout << s.empty() << endl;
    s.empty() == 0 ? cout << "False" << endl : cout << "True" << endl;

    return 0;
    ;
}
