//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    25-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *next;
};

struct node *head;

void init()
{
    head = NULL;
}

void insertfirst(int element)
{
    struct node *New;
    New = (struct node *)malloc(sizeof(struct node));
    New->value = element;
    New->next = NULL;
    New->next = head;
    head = New;
}

void print()
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur = head;
    int count = 0;
    while (cur != NULL)
    {
        printf("%d->", cur->value);
        count++;
        cur = cur->next;
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
    while (cur != NULL && cur->value != ele)
    {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (prev != NULL)
        prev->next = cur->next;
    else
        head = head->next;
    free(cur);
}

int searchitem(int ele)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->value == ele)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void insertlast(int ele)
{
    struct node *New;
    New = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        insertfirst(ele);
        return;
    }
    New->value = ele;
    New->next = NULL;
    struct node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = New;
}

void deletelast()
{
    if (head == NULL)
    {
        printf("list is empty and nothing to delete\n");
        return;
    }
    struct node *cur = head;
    struct node *prev = NULL;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    free(cur);
}

void deletefirst()
{
    if (head == NULL)
    {
        printf("list is empty and nothing to delete\n");
        return;
    }
    struct node *cur = head;
    head = head->next;
    free(cur);
}

void insertafter(int elem, int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->value = elem;
    temp->next = NULL;
    struct node *prev = head;
    while (prev != NULL && prev->value != num)
    {
        prev = prev->next;
    }
    if (prev == NULL)
    {
        printf("%d doesn't exist!\n", num);
        free(temp);
        return;
    }
    temp->next = prev->next;
    prev->next = temp;
}

void deleteAfter(int num)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct node *cur = head;
    while (cur != NULL && cur->value != num)
    {
        cur = cur->next;
    }

    if (cur == NULL || cur->next == NULL)
    {
        printf("%d doesn't exist or it is the last element!\n", num);
        return;
    }

    struct node *temp = cur->next;
    cur->next = temp->next;
    free(temp);
}

void printReverse(struct node *head)
{
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d->", head->value);
}

void reverselist()
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
    head = prev;
}

void sum()
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

    prevPrev->value = newValue;
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

    prevPrev->next = cur;
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
        printf("\n1. Insert new item. 2. Delete item. 3. Search item. 4. Insert Last. 5. Print. 6.Delete Last 7.Delete First 8.Insert After 9.Print Linked List in Reverse way. 10.Sum 11.Make the linked list reverse 12. ReplaceFirst. 13. ReplaceLast. 14. ReplaceAfter. 15. ReplaceBefore. 16. InsertAtK. 17. InsertAtMiddle. 18. DeleteBefore. 19. SearchEven. 20. SearchOdd. 21. Delete After. 22. Exit\n--------------------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter element to insert: ");
            scanf("%d", &element);
            insertfirst(element);
        }
        else if (ch == 2)
        {
            int de;
            printf("Enter element to delete: ");
            scanf("%d", &de);
            deleteitem(de);
        }
        else if (ch == 3)
        {
            int se, reply;
            printf("Enter element to search: ");
            scanf("%d", &se);
            reply = searchitem(se);
            if (reply == 1)
                printf("Element found\n");
            else
                printf("Element not found\n");
        }
        else if (ch == 4)
        {
            int le;
            printf("Enter element to insert at last: ");
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
            printf("Enter element to insert: ");
            scanf("%d", &ie);
            printf("Enter the element after which to insert: ");
            scanf("%d", &p);
            insertafter(ie, p);
        }
        else if (ch == 9)
        {
            printReverse(head);
            printf("NULL\n");
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
        {
            int newValue;
            printf("Enter the new value: ");
            scanf("%d", &newValue);
            replaceFirst(newValue);
        }
        else if (ch == 13)
        {
            int newValue;
            printf("Enter the new value: ");
            scanf("%d", &newValue);
            replaceLast(newValue);
        }
        else if (ch == 14)
        {
            int existingValue, newValue;
            printf("Enter the existing value: ");
            scanf("%d", &existingValue);
            printf("Enter the new value: ");
            scanf("%d", &newValue);
            replaceAfter(existingValue, newValue);
        }
        else if (ch == 15)
        {
            int existingValue, newValue;
            printf("Enter the existing value: ");
            scanf("%d", &existingValue);
            printf("Enter the new value: ");
            scanf("%d", &newValue);
            replaceBefore(existingValue, newValue);
        }
        else if (ch == 16)
        {
            int element, position;
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert at: ");
            scanf("%d", &position);
            insertAtK(element, position);
        }
        else if (ch == 17)
        {
            int element;
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insertAtMiddle(element);
        }
        else if (ch == 18)
        {
            int existingValue;
            printf("Enter the existing value: ");
            scanf("%d", &existingValue);
            deleteBefore(existingValue);
        }
        else if (ch == 19)
        {
            searchEven();
        }
        else if (ch == 20)
        {
            searchOdd();
        }
        else if (ch == 21)
        {
            int num;
            printf("Enter the value after which to delete: ");
            scanf("%d", &num);
            deleteAfter(num);
        }
        else if (ch == 22)
        {
            return 0;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
