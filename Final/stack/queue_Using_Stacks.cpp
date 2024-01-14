#include <iostream>
#include <stack>
using namespace std;

const int MAX_SIZE = 100;

stack<int> s1, s2;

void enqueue(int data)
{
	if (s1.size() == MAX_SIZE)
	{
		cout << "Queue is Full" << endl;
		return;
	}
	s1.push(data);
}

void dequeue()
{
	if (s1.empty() && s2.empty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}

	if (s2.empty())
	{
		while (!s1.empty())
		{
			int x = s1.top();
			s1.pop();
			s2.push(x);
		}
	}

	int dequeuedValue = s2.top();
	s2.pop();
	cout << "Dequeued value: " << dequeuedValue << endl;
}

void display()
{
	stack<int> tempStack = s1;
	while (!tempStack.empty())
	{
		cout << tempStack.top() << " ";
		tempStack.pop();
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
