//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    29-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

struct node // make node for linked list using structure
{
    int value;         // value part of node contains the element
    struct node *next; // the next part of node contains the address of next element of list
};

struct node *head; // contains the address of first element of linked list

void init()
{
    head = NULL; // initialize the beginning(head) of list to NULL
}

void insertfirst(int element) // inserts element in linked list
{
    struct node *New;
    New = (struct node *)malloc(sizeof(struct node)); // New named node declared with size of node declared before
    New->value = element;                             // inserts the new element to the value part of node New
    New->next = NULL;                                 // makes the next part of node New NULL so that no garbage value remains
    New->next = head;                                 // the address of previously first node, which was stored in head is now assigned to next part of node New
    head = New;                                       // the address of new first element which is present in node New is assigned to head node
}

void print()
{
    if (head == NULL) // condition to check whether list is empty
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur = head;
    int count;
    count = 0;
    while (cur != NULL) // the loop traverse until it gets any NULL node
    {
        printf("%d->", cur->value);
        count++;         // counts the number of nodes or elements present in list
        cur = cur->next; // moves cur pointer to next node to check and get value
    }
    printf("NULL\n");
    printf("number of nodes %d\n", count);
}

void deleteitem(int ele)
{
    if (head == NULL)
    {
        printf("list empty!");
        return;
    }
    struct node *cur = head;
    struct node *prev = NULL;
    while (cur->value != ele)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev != NULL)
        prev->next = cur->next;
    else
        head = NULL;
    free(cur);
}

int searchitem(int ele)
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        if (temp->value == ele)
            return 1; // element is found
        temp = temp->next;
    }
    return 0;
}

void insertlast(int ele) // insert at the last of linked list
{
    struct node *New;
    New = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        insertfirst(ele);
    }
    else
    {
        New->value = ele;
        New->next = NULL;
        struct node *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = New;
    }
}

void deletelast() // delete the last element
{
    if (head == NULL)
    {
        printf("list is empty and nothing to delete\n");
    }
    struct node *cur = head;
    struct node *prev = NULL;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev->next != NULL)
        prev->next = NULL;
    free(cur);
}

void deletefirst() // delete the first element
{
    struct node *cur;
    if (head == NULL)
        printf("list is empty and nothing to delete\n");
    cur = head;
    head = head->next;
    free(cur);
}

void insertafter(int elem, int num) // inserts element for any given element present in linked list
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->value = elem;
    temp->next = NULL;
    struct node *prev = head;
    while ((prev->value != num) && (prev->next != NULL))
    {
        prev = prev->next;
    }
    if (prev->next == NULL)
        printf("%d doesn't exist!\n", num);
    else
    {
        temp->next = prev->next;
        prev->next = temp;
    }
}

void printReverse(struct node *head) // print the linked list in reverse way using recursion
{
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d->", head->value);
}

void reverselist() // reverse the linked list
{
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev; // points the head pointer to prev as it the new head or beginning in reverse list
}

void sum() // sum of elements of the linked list
{
    int sum = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        sum += temp->value;
        temp = temp->next;
    }
    printf("Sum of elements: %d\n", sum);
}

void replaceFirst(int newValue)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    head->value = newValue;
}

void replaceLast(int newValue)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->value = newValue;
}

void replaceAfter(int existingValue, int newValue)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct node *cur = head;
    while (cur != NULL && cur->value != existingValue)
    {
        cur = cur->next;
    }

    if (cur == NULL || cur->next == NULL)
    {
        printf("%d doesn't exist or it is the last element!\n", existingValue);
        return;
    }

    cur->next->value = newValue;
}

void replaceBefore(int existingValue, int newValue)
{
    if (head == NULL || head->value == existingValue)
    {
        printf("%d doesn't exist or it is the first element!\n", existingValue);
        return;
    }

    struct node *cur = head->next;
    struct node *prev = head;
    while (cur != NULL && cur->value != existingValue)
    {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("%d doesn't exist!\n", existingValue);
        return;
    }

    prev->value = newValue;
}

void insertAtK(int element, int position)
{
    if (position <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        insertfirst(element);
        return;
    }

    struct node *New = (struct node *)malloc(sizeof(struct node));
    New->value = element;

    struct node *cur = head;
    int count = 1;
    while (cur != NULL && count < position - 1)
    {
        cur = cur->next;
        count++;
    }

    if (cur == NULL)
    {
        printf("Invalid position!\n");
        free(New);
        return;
    }

    New->next = cur->next;
    cur->next = New;
}

void insertAtMiddle(int element)
{
    if (head == NULL)
    {
        insertfirst(element);
        return;
    }

    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *New = (struct node *)malloc(sizeof(struct node));
    New->value = element;
    New->next = slow->next;
    slow->next = New;
}

void deleteBefore(int existingValue)
{
    if (head == NULL || head->value == existingValue)
    {
        printf("%d doesn't exist or it is the first element!\n", existingValue);
        return;
    }

    struct node *cur = head->next;
    struct node *prev = head;
    struct node *prevPrev = NULL;

    while (cur != NULL && cur->value != existingValue)
    {
        prevPrev = prev;
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("%d doesn't exist!\n", existingValue);
        return;
    }

    if (prevPrev == NULL)
    {
        head = cur;
    }
    else
    {
        prevPrev->next = cur;
    }
    free(prev);
}

void searchEven()
{
    struct node *temp = head;
    int found = 0;

    while (temp != NULL)
    {
        if (temp->value % 2 == 0)
        {
            printf("%d is even\n", temp->value);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
    {
        printf("No even numbers found!\n");
    }
}

void searchOdd()
{
    struct node *temp = head;
    int found = 0;

    while (temp != NULL)
    {
        if (temp->value % 2 != 0)
        {
            printf("%d is odd\n", temp->value);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
    {
        printf("No odd numbers found!\n");
    }
}

int main()
{
    init();

    int ch, element;
    while (1)
    {
        printf("\n1. Insert new item. 2. Delete item. 3. Search item. 4. Insert Last. 5. Print. 6.Delete Last 7.Delete First 8.Insert After 9.Print Linked List in Reverse way. 10.Sum 11.Make the linked list reverse 12.Exit\n--------------------------------------------------------------------------------------\n");
        printf("enter choice of input: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("enter element to list: ");
            scanf("%d", &element);
            insertfirst(element);
        }
        else if (ch == 2)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d", &de);
            deleteitem(de);
        }
        else if (ch == 3)
        {
            int se, reply;
            printf("enter element to search ");
            scanf("%d", &se);
            reply = searchitem(se);
            if (reply == 1)
                printf("element found\n");
            else
                printf("element not found\n");
        }
        else if (ch == 4)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d", &le);
            insertlast(le);
        }
        else if (ch == 5)
        {
            print();
        }
        else if (ch == 6)
        {
            deletelast();
        }
        else if (ch == 7)
        {
            deletefirst();
        }
        else if (ch == 8)
        {
            int ie, p;
            printf("enter element to insert: ");
            scanf("%d", &ie);
            printf("enter after which element to insert: ");
            scanf("%d", &p);
            insertafter(ie, p);
        }
        else if (ch == 9)
        {
            printReverse(head);
        }
        else if (ch == 10)
        {
            sum();
        }
        else if (ch == 11)
        {
            reverselist();
        }
        else if (ch == 12)
            return 0;
        else
            return 0;
    }
    return 0;
}
