#include <iostream>
#include <string>
using namespace std;

bool isValidExpression(string exp)
{
    int balance = 0;

    for (char c : exp)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            balance++;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            balance--;
        }

        if (balance < 0)
        {
            return false; // More closing brackets than opening brackets
        }
    }

    return balance == 0; // Check if all brackets are balanced
}

int main()
{
    string exp;
    cin >> exp;

    if (isValidExpression(exp))
    {
        cout << "Expression brackets are balanced." << endl;
    }
    else
    {
        cout << "Expression brackets are not balanced." << endl;
    }

    return 0;
}
