#include <bits/stdc++.h>
using namespace std;
#define size 100

int top = -1;
char arr[size];

void push(char ele)
{
    if (top > 0 && arr[top] == ele && arr[top] == arr[top - 1])
    {
        return; // Ignore adjacent duplicates
    }

    if (top == size - 1)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        top++;
        arr[top] = ele;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        top--;
    }
}

void display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    for (char c : input)
    {
        push(c);
    }

    cout << "Processed string: ";
    display();

    return 0;
}
