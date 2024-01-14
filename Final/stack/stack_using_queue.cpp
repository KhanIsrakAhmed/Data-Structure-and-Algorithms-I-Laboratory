#include <bits/stdc++.h>
using namespace std;

class StackUsingQueue
{
    queue<int> queue1, queue2;

public:
    void push(int data)
    {
        queue2.push(data);
        while (!queue1.empty())
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1, queue2);
    }

    int pop()
    {
        if (queue1.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int topValue = queue1.front();
        queue1.pop();
        return topValue;
    }

    void display()
    {
        queue<int> tempQueue = queue1;
        while (!tempQueue.empty())
        {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main()
{
    StackUsingQueue stack;

    stack.push(20);
    stack.push(30);
    stack.push(45);
    stack.push(69);

    cout << "Stack contents before pop:" << endl;
    stack.display();

    int poppedValue = stack.pop();
    if (poppedValue != -1)
    {
        cout << "Popped value: " << poppedValue << endl;
    }

    cout << "Stack contents after pop:" << endl;
    stack.display();

    return 0;
}
