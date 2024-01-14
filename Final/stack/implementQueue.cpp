#include <bits/stdc++.h>
using namespace std;
#define size 100

int s1[size], s2[size];
int top1 = -1, top2 = -1, cnt = 0;

void push1(int data)
{
    if (top1 == size - 1)
        cout << "Over flow: " << endl;
    else
    {
        top1++;
        s1[top1] = data;
    }
}

void push2(int data)
{
    if (top2 == size - 1)
        cout << "Over flow: " << endl;
    else
    {
        top2++;
        s2[top2] = data;
    }
}

int pop1()
{
    return s1[top1--];
}

int pop2()
{
    return s2[top2--];
}

void enqueue(int x)
{
    if (cnt == size)
        cout << "Queue is Full" << endl;
    else
    {
        push1(x);
        cnt++;
    }
}

void dequeue()
{
    if (top1 == -1 && top2 == -1)
        cout << "Queue is Empty" << endl;
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            int x = pop1();
            push2(x);
        }

        int a = pop2();
        cout << "Dequeued value: " << a << endl;
        cnt--;

        for (int i = 0; i < cnt; i++)
        {
            int x = pop2();
            push1(x);
        }
    }
}

void display()
{
    for (int i = 0; i <= top1; i++)
    {
        cout << s1[i] << " ";
    }
    cout << endl;
}

int main()
{
    enqueue(20);
    enqueue(30);
    enqueue(45);
    enqueue(69);

    cout << "Queue contents before dequeue:" << endl;
    display();

    dequeue();

    cout << "Queue contents after dequeue:" << endl;
    display();

    return 0;
}
