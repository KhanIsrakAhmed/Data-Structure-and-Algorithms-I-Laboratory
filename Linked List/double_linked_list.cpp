//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    25-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct double_linked_list
{
    node *head;
    node *tail;

    double_linked_list()
    {
        head = NULL;
        tail = NULL;
        // head->data = 0;
        // head->next = nullptr;
    }

    node *search_in_list(int val)
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->data == val)
                return temp;
            else
                temp = temp->next;
        }
        return nullptr;
    }

    node *search_in_list_reverse(int val)
    {
        node *temp = tail;
        while (temp != NULL)
        {
            if (temp->data == val)
                return temp;
            else
                temp = temp->prev;
        }
        return NULL;
    }

    void insert_first(int val)
    {
        if (head != NULL)
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = head;

            head->prev = newNode;

            head = newNode;
        }
        else
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = NULL;

            head = newNode;
            tail = newNode;
        }
    }

    void insert_last(int val)
    {
        if (tail != NULL)
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->next = NULL;
            newNode->prev = tail;

            tail->next = newNode;

            tail = newNode;
        }
        else
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = NULL;

            head = newNode;
            tail = newNode;
        }
    }

    void insert_middle(int new_val, int prev_val)
    {
        node *newNode = new node;
        newNode->data = new_val;

        node *temp = search_in_list(prev_val);
        node *temp1 = temp->next;

        newNode->next = temp1;
        newNode->prev = temp;

        temp->next = newNode;
        temp1->prev = newNode;
    }

    void insert_in_order(int val)
    {
    }

    void delete_first()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            node *temp = head;
            head = NULL;
            tail = NULL;

            delete temp;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;

            delete temp;
        }
    }

    void delete_last()
    {
        if (tail == NULL)
        {
            return;
        }
        else if (tail->prev == NULL)
        {
            node *temp = tail;
            tail = NULL;
            head = NULL;

            delete temp;
        }
        else
        {
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;

            delete temp;
        }
    }

    void convert_to_circular_list()
    {
        tail->next = head;
        head->prev = tail;
    }

    void show_list()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }

    void show_list_circular()
    {
    }
};

int main()
{
    double_linked_list linked_list;
    int ch;
    int val, prev_val;
    node *y = new node;

    while (1)
    {
        cout << "---MENU---" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Show All " << endl;
        cout << "3. Search " << endl;
        cout << "4. Insert Last " << endl;
        cout << "5. Insert Middle " << endl;
        cout << "6. Insert In Order " << endl;
        cout << "7. Exit " << endl;

        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value of data: ";

            cin >> val;
            linked_list.insert_first(val);
            break;

        case 2:
            linked_list.show_list();
            break;

        case 3:
            cout << "Enter a value to search in the list: ";

            cin >> val;

            y = linked_list.search_in_list(val);
            if (y != nullptr)
            {
                cout << "Node found!" << endl;
                cout << y->data << endl;
            }
            else
            {
                cout << "Node not found!" << endl;
            }
            break;

        case 4:
            cout << "Enter the value of data: ";
            cin >> val;
            linked_list.insert_last(val);
            break;

        case 5:
            cout << "Enter the new value of data: ";
            cin >> val;
            cout << "Enter the prev value of data: ";
            cin >> prev_val;
            linked_list.insert_middle(val, prev_val);
            break;

        case 6:
            cout << "Enter the value of data: ";
            cin >> val;
            linked_list.insert_in_order(val);
            break;

        case 7:
            return 0;
            break;

        default:
            cout << "Wrong input!" << endl;
        }
    }

    return 0;
}