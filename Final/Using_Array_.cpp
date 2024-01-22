//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    08-08-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int stackk[100]; // LIFO
int top;

void push(int value)
{
    if (top >= 99)
    {
        cout << "STACK over flow" << endl;
    }
    else
    {
        top++;
        stackk[top] = value;
    }
}

int pop()
{
    int value;
    if (top < 0)
    {
        cout << "Stack under flow" << endl;
        return -1;
    }
    else
    {
        value = stackk[top];
        top--;
        return value;
    }
}

void printStack()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stackk[i] << " ";
    }
}

int main()
{
    top = -1;
    push(20);
    push(1);
    push(15);

    pop();
    pop();
    pop();
    pop();

    return 0;
}
