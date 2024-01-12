//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    13-07-2023     *************************\


#include <iostream>
#include <limits>

using namespace std;

class CircularQueue
{
private:
    static const int MAX_SIZE = 100;
    int queue[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    void enqueue();
    void dequeue();
    void display();
};

void CircularQueue::enqueue()
{
    int val;
    if ((rear + 1) % MAX_SIZE == front)
        cout << "Queue Overflow" << endl;
    else
    {
        if (front == -1)
            front = 0;
        cout << "Insert the element in the queue: ";
        cin >> val;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = val;
    }
}

void CircularQueue::dequeue()
{
    if (front == -1 && rear == -1)
        cout << "Queue Underflow" << endl;
    else
    {
        cout << "Element deleted from the queue: " << queue[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX_SIZE;
    }
}

void CircularQueue::display()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are: ";
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
            cout << queue[i] << " ";
        cout << queue[rear] << endl;
    }
}

int main()
{
    CircularQueue myQueue;

    int choice;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all elements of queue" << endl;
    cout << "4) Exit" << endl;

    while (choice != 4)
    {
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            myQueue.enqueue();
            break;
        case 2:
            myQueue.dequeue();
            break;
        case 3:
            myQueue.display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
