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

ListNode *reverseKGroup(ListNode *head, int k)
{

    ListNode *retHead = NULL;
    if (k <= 1 || head->next == NULL)
    {
        return head;
    }

    ListNode *prevKthNode = NULL;
    ListNode *currKthNode = NULL;
    ListNode *currKthNodeNext = NULL;

    ListNode *prevNode = head;
    ListNode *currNode = head->next;
    ListNode *nextNode;

    int cnt = 1;
    ListNode *ptr = head;

    while (ptr)
    {
        if (cnt == k)
        {
            currKthNode = ptr;
            currKthNodeNext = currKthNode->next;

            if (!retHead)
            {
                retHead = currKthNode;
            }

            if (prevKthNode)
            {
                prevKthNode->next = currKthNode;
            }
            prevNode->next = currKthNodeNext;
            prevKthNode = prevNode;

            while (currNode != currKthNodeNext)
            {
                nextNode = currNode->next;
                currNode->next = prevNode;

                prevNode = currNode;
                currNode = nextNode;
            }

            prevNode = currKthNodeNext;
            currNode = prevNode ? prevNode->next : NULL;
            cnt = 1;
            ptr = currKthNodeNext;
        }
        else
        {
            ptr = ptr->next;
            cnt++;
        }
    }

    return retHead ? retHead : head;
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

    int k;
    cin >> k;

    printList(reverseKGroup(l1, k));

    return 0;
}
