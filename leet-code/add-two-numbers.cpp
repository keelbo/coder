#include <iostream>

using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *appendListNode(int val, ListNode *curNodePtr)
{

    ListNode newNode(val);
    if (curNodePtr != NULL)
    {
        curNodePtr->next = &newNode;
    }

    cout << "appendListNode : " << val << " " << curNodePtr->val << " ";
    cout << curNodePtr->next->val << " " << &newNode << " " << newNode.val << endl;
    return &newNode;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *curNodePtr = NULL;
    ListNode *rootNodePtr = NULL;

    int carry = 0;

    while (l1 != NULL && l2 != NULL)
    {
        int digitSum = l1->val + l2->val + carry;

        curNodePtr = appendListNode(digitSum / 10, curNodePtr);
        if (rootNodePtr == NULL)
        {
            rootNodePtr = curNodePtr;
        }
        carry = digitSum % 10;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL)
    {
        int digitSum = l1->val + carry;

        curNodePtr = appendListNode(digitSum / 10, curNodePtr);
        if (rootNodePtr == NULL)
        {
            rootNodePtr = curNodePtr;
        }
        carry = digitSum % 10;
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        int digitSum = l2->val + carry;

        curNodePtr = appendListNode(digitSum / 10, curNodePtr);
        if (rootNodePtr == NULL)
        {
            rootNodePtr = curNodePtr;
        }
        carry = digitSum % 10;
        l2 = l2->next;
    }
    if (carry)
    {
        appendListNode(carry, curNodePtr);
    }

    return rootNodePtr;
}

void printListNode(ListNode *l)
{
    while (l != NULL)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ListNode l1(2), *temp, *temp1;
    ListNode l2(5);
    // (2 -> 4 -> 3) + (5 -> 6 -> 4)
    appendListNode(4, &l1);
    temp = &l1;
    cout << temp->val << " ";
    temp1 = temp->next;
    cout << temp1->val << endl;
    // appendListNode(3, l1.next);

    // printListNode(&l1);

    // appendListNode(6, &l2);
    // appendListNode(4, l2.next);
    // printListNode(&l2);

    // printListNode(addTwoNumbers(&l1, &l2));

    return 0;
}
