//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    21-08-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

#define size 100
int queue[size];
int front = -1, rear = -1;

void enqueue()
{
    if (rear == size - 1)
        cout << "Queue Overflow" << endl;
    else
    {
        int val;
        if (front == -1)
            front = 0;
        cout << "Insert the element in queue: ";
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        cout << "Queue Underflow" << endl;
    else
    {
        cout << "Element deleted from queue is: " << queue[front] << endl;
        front++;
    }
}

void display()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main()
{
    int ch;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all elements of queue" << endl;
    cout << "4) Exit" << endl;

    while (ch != 4)
    {
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
