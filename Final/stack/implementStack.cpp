#include <bits/stdc++.h>
using namespace std;

#define size 100

int queue1[size], queue2[size];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

void enqueue1(int data)
{
    if (rear1 == size - 1)
        cout << "Queue 1 is Full" << endl;
    else
    {
        if (front1 == -1)
            front1 = 0;
        rear1++;
        queue1[rear1] = data;
    }
}

int dequeue1()
{
    int data = queue1[front1];
    if (front1 == rear1)
    {
        front1 = rear1 = -1;
    }
    else
    {
        front1++;
    }
    return data;
}

void enqueue2(int data)
{
    if (rear2 == size - 1)
        cout << "Queue 2 is Full" << endl;
    else
    {
        if (front2 == -1)
            front2 = 0;
        rear2++;
        queue2[rear2] = data;
    }
}

int dequeue2()
{
    int data = queue2[front2];
    if (front2 == rear2)
    {
        front2 = rear2 = -1;
    }
    else
    {
        front2++;
    }
    return data;
}

void push(int data)
{
    enqueue1(data);
}

int pop()
{
    if (front1 == -1 && front2 == -1)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }

    int data;
    if (front1 != -1)
    {
        while (front1 != rear1)
        {
            enqueue2(dequeue1());
        }
        data = dequeue1();
    }
    else
    {
        while (front2 != rear2)
        {
            enqueue1(dequeue2());
        }
        data = dequeue2();
    }
    return data;
}

void display()
{
    if (front1 == -1 && front2 == -1)
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    cout << "Stack contents: ";
    if (front1 != -1)
    {
        for (int i = front1; i <= rear1; i++)
        {
            cout << queue1[i] << " ";
        }
    }
    else
    {
        for (int i = front2; i <= rear2; i++)
        {
            cout << queue2[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    push(20);
    push(30);
    push(45);
    push(69);

    cout << "Stack contents before pop:" << endl;
    display();

    int poppedValue = pop();
    if (poppedValue != -1)
    {
        cout << "Popped value: " << poppedValue << endl;
    }

    cout << "Stack contents after pop:" << endl;
    display();

    return 0;
}
