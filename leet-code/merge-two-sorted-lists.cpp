#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }

    ListNode *head = l1->val < l2->val ? l1 : l2;
    ListNode *nextNode;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            nextNode = l1->next;
            l1->next = l2;
            l1 = nextNode;
        }
        else
        {
            nextNode = l2->next;
            l2->next = l1;
            l2 = nextNode;
        }
    }
    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = NULL, *l1Ptr;
    ListNode *l2 = NULL, *l2Ptr;

    int n;
    cin >> n;
    while (n--)
    {
        int elm;
        cin >> elm;
        if (l1 == NULL)
        {
            l1 = new ListNode(elm);
            l1Ptr = l1;
        }
        else
        {
            l1Ptr->next = new ListNode(elm);
            l1Ptr = l1Ptr->next;
        }
    }

    cin >> n;
    while (n--)
    {
        int elm;
        cin >> elm;
        if (l2 == NULL)
        {
            l2 = new ListNode(elm);
            l2Ptr = l2;
        }
        else
        {
            l2Ptr->next = new ListNode(elm);
            l2Ptr = l2Ptr->next;
        }
    }

    printList(mergeTwoLists(l1, l2));

    return 0;
}
