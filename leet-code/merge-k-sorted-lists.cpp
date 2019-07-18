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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = NULL;
    ListNode *ptr = NULL;

    bool allNodeExosted = false;

    if (lists.size() < 1)
    {
        return head;
    }

    while (!allNodeExosted)
    {
        int listExostedCnt = 0;

        ListNode *minNode = NULL;
        int minNodeListIndex;

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] == NULL)
            {
                listExostedCnt++;
            }
            else
            {
                if (minNode == NULL || minNode->val >= lists[i]->val)
                {
                    minNode = lists[i];
                    minNodeListIndex = i;
                }
            }
        }

        if (listExostedCnt == lists.size())
        {

            allNodeExosted = true;
        }
        else
        {

            if (ptr)
            {
                ptr->next = minNode;
                ptr = ptr->next;
            }
            if (head == NULL)
            {
                head = minNode;
                ptr = minNode;
            }

            if (lists[minNodeListIndex])
            {
                lists[minNodeListIndex] = lists[minNodeListIndex]->next;
            }
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
    vector<ListNode *> lists;

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

    lists.push_back(l1);
    lists.push_back(l2);
    printList(mergeKLists(lists));

    return 0;
}
